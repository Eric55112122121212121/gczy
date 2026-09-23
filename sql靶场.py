from flask import Flask, request, render_template_string, redirect, session
import sqlite3
import webbrowser
import threading
import datetime
import os

app = Flask(__name__)
app.secret_key = "sqli_demo_secret_key_2024"

# ========== 初始化数据库（保证admin唯一）==========
def init_db():
    conn = sqlite3.connect('test.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT, 
        username TEXT UNIQUE, 
        password TEXT
    )''')
    c.execute("DELETE FROM users WHERE username='admin'")
    c.execute("INSERT INTO users (username, password) VALUES ('admin', '123456')")
    c.execute("INSERT OR IGNORE INTO users (username, password) VALUES ('guest', 'guest123')")
    conn.commit()
    conn.close()

init_db()

# ========== 登录页HTML（删除SQL展示）==========
LOGIN_HTML = """
<!DOCTYPE html>
<html lang="zh-CN">
    <head>
        <meta charset="UTF-8">
        <title>登录</title>
        <style>
            body { background: #f0f2f5; font-family: "Microsoft YaHei", Arial, sans-serif; padding: 20px; }
            .container { max-width: 800px; margin: 0 auto; background: white; padding: 30px; border-radius: 10px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }
            h2 { color: #333; text-align: center; border-bottom: 2px solid #4CAF50; padding-bottom: 10px; }
            .form-group { margin: 20px 0; }
            label { display: block; margin-bottom: 8px; font-weight: bold; color: #555; }
            input[type="text"], input[type="password"] { width: 100%; padding: 12px; border: 1px solid #ddd; border-radius: 4px; font-size: 16px; }
            button { width: 100%; padding: 14px; background: #4CAF50; color: white; border: none; border-radius: 4px; font-size: 18px; cursor: pointer; margin-top: 10px;}
            button:hover { background: #45a049; }
            .result-box { margin-top: 30px; padding: 20px; background: #f8f9fa; border-left: 5px solid #007bff; border-radius: 4px; word-break: break-all;}
            .success { color: #155724; background-color: #d4edda; border-color: #c3e6cb; }
            .error { color: #721c24; background-color: #f8d7da; border-color: #f5c6cb; }
            .switch-link { text-align: center; margin-top: 15px; font-size: 14px; }
            .switch-link a { color: #007bff; text-decoration: none; }
            .switch-link a:hover { text-decoration: underline; }
        </style>
    </head>
    <body>
        <div class="container">
            <h2>🔐 登录</h2>
            <form method="POST">
                <div class="form-group">
                    <label>用户名:</label>
                    <input type="text" name="username" value="{{ username or '' }}" placeholder="请输入用户名">
                </div>
                <div class="form-group">
                    <label>密码:</label>
                    <input type="password" name="password" value="{{ password or '' }}" placeholder="请输入密码">
                </div>
                <button type="submit">登录</button>
            </form>
            <div class="switch-link">
                没有账号？<a href="/register">去注册</a>
            </div>
            {% if result %}
                <div class="result-box {{ 'success' if success else 'error' }}">
                    <h3>{{ '✅ 登录成功' if success else '❌ 登录失败' }}</h3>
                    <p>{{ result }}</p>
                </div>
            {% endif %}
        </div>
    </body>
</html>
"""

# ========== 注册页HTML（删除SQL展示）==========
REGISTER_HTML = """
<!DOCTYPE html>
<html lang="zh-CN">
    <head>
        <meta charset="UTF-8">
        <title>注册</title>
        <style>
            body { background: #f0f2f5; font-family: "Microsoft YaHei", Arial, sans-serif; padding: 20px; }
            .container { max-width: 800px; margin: 0 auto; background: white; padding: 30px; border-radius: 10px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }
            h2 { color: #333; text-align: center; border-bottom: 2px solid #2196F3; padding-bottom: 10px; }
            .form-group { margin: 20px 0; }
            label { display: block; margin-bottom: 8px; font-weight: bold; color: #555; }
            input[type="text"], input[type="password"] { width: 100%; padding: 12px; border: 1px solid #ddd; border-radius: 4px; font-size: 16px; }
            button { width: 100%; padding: 14px; background: #2196F3; color: white; border: none; border-radius: 4px; font-size: 18px; cursor: pointer; margin-top: 10px;}
            button:hover { background: #1976D2; }
            .result-box { margin-top: 30px; padding: 20px; background: #f8f9fa; border-left: 5px solid #FF9800; border-radius: 4px; word-break: break-all;}
            .success { color: #155724; background-color: #d4edda; border-color: #c3e6cb; }
            .error { color: #721c24; background-color: #f8d7da; border-color: #f5c6cb; }
            .switch-link { text-align: center; margin-top: 15px; font-size: 14px; }
            .switch-link a { color: #007bff; text-decoration: none; }
            .switch-link a:hover { text-decoration: underline; }
        </style>
    </head>
    <body>
        <div class="container">
            <h2>📝 注册</h2>
            <form method="POST">
                <div class="form-group">
                    <label>用户名:</label>
                    <input type="text" name="username" value="{{ username or '' }}" placeholder="请输入用户名">
                </div>
                <div class="form-group">
                    <label>密码:</label>
                    <input type="password" name="password" value="{{ password or '' }}" placeholder="请输入密码">
                </div>
                <button type="submit">提交注册</button>
            </form>
            <div class="switch-link">
                已有账号？<a href="/">去登录</a>
            </div>
            {% if result %}
                <div class="result-box {{ 'success' if success else 'error' }}">
                    <h3>{{ '✅ 注册成功' if success else '❌ 注册失败' }}</h3>
                    <p>{{ result }}</p>
                </div>
            {% endif %}
        </div>
    </body>
</html>
"""

# ========== 普通用户中心HTML（删除SQL展示）==========
PROFILE_HTML = """
<!DOCTYPE html>
<html lang="zh-CN">
    <head>
        <meta charset="UTF-8">
        <title>用户中心</title>
        <style>
            body { background: #f0f2f5; font-family: "Microsoft YaHei", Arial, sans-serif; padding: 20px; }
            .container { max-width: 800px; margin: 0 auto; background: white; padding: 30px; border-radius: 10px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); }
            h2 { color: #333; text-align: center; border-bottom: 2px solid #9C27B0; padding-bottom: 10px; }
            .user-info { margin: 20px 0; padding: 20px; background: #f8f9fa; border-radius: 4px; }
            .info-item { margin: 10px 0; font-size: 16px; }
            .logout-btn { width: 100%; padding: 14px; background: #f44336; color: white; border: none; border-radius: 4px; font-size: 18px; cursor: pointer; margin-top: 20px;}
            .logout-btn:hover { background: #d32f2f; }
        </style>
    </head>
    <body>
        <div class="container">
            <h2>👤 用户中心</h2>
            <div class="user-info">
                <div class="info-item"><strong>当前登录用户：</strong>{{ username }}</div>
                <div class="info-item"><strong>用户ID：</strong>{{ user_data[0] }}</div>
                <div class="info-item"><strong>用户名：</strong>{{ user_data[1] }}</div>
                <div class="info-item"><strong>密码：</strong>{{ user_data[2] }}</div>
            </div>
            <form action="/logout" method="GET">
                <button type="submit" class="logout-btn">退出登录</button>
            </form>
        </div>
    </body>
</html>
"""

# ========== 管理员后台HTML（删除SQL展示面板）==========
ADMIN_DASHBOARD_HTML = """
<!DOCTYPE html>
<html lang="zh-CN">
    <head>
        <meta charset="UTF-8">
        <title>管理员后台</title>
        <style>
            body { background: #1a1a2e; font-family: "Microsoft YaHei", Arial, sans-serif; padding: 20px; color: #eee; }
            .container { max-width: 1000px; margin: 0 auto; background: #16213e; padding: 30px; border-radius: 10px; box-shadow: 0 2px 10px rgba(0,0,0,0.3); }
            h2 { color: #00d4ff; text-align: center; border-bottom: 2px solid #0f3460; padding-bottom: 10px; }
            .admin-header { display: flex; justify-content: space-between; align-items: center; margin-bottom: 20px; }
            .welcome-text { font-size: 18px; color: #4CAF50; }
            .logout-btn { padding: 10px 20px; background: #f44336; color: white; border: none; border-radius: 4px; cursor: pointer; text-decoration: none; }
            .logout-btn:hover { background: #d32f2f; }
            .user-table { width: 100%; border-collapse: collapse; margin-top: 20px; }
            .user-table th, .user-table td { padding: 12px; text-align: left; border-bottom: 1px solid #0f3460; }
            .user-table th { background: #0f3460; color: #00d4ff; }
            .user-table tr:hover { background: #1a5a8a; }
            .user-id { color: #4CAF50; font-weight: bold; }
            .username { color: #ff9800; }
            .password { color: #f44336; font-family: monospace; }
            .btn-delete { padding: 5px 10px; background: #f44336; color: white; border: none; border-radius: 3px; cursor: pointer; text-decoration: none; }
            .btn-delete:hover { background: #d32f2f; }
            .btn-disabled { padding: 5px 10px; background: #666; color: #999; border: none; border-radius: 3px; cursor: not-allowed; }
        </style>
    </head>
    <body>
        <div class="container">
            <div class="admin-header">
                <h2>🔧 管理员后台</h2>
                <a href="/logout" class="logout-btn">退出登录</a>
            </div>
            <div class="welcome-text">欢迎，{{ username }}！当前时间：{{ current_time }}</div>
            <h3 style="color: #00d4ff; margin-top: 30px;">用户管理</h3>
            <table class="user-table">
                <thead>
                    <tr>
                        <th>ID</th>
                        <th>用户名</th>
                        <th>密码</th>
                        <th>操作</th>
                    </tr>
                </thead>
                <tbody>
                    {% for user in users %}
                        <tr>
                            <td class="user-id">{{ user[0] }}</td>
                            <td class="username">{{ user[1] }}</td>
                            <td class="password">{{ user[2] }}</td>
                            <td>
                                {% if user[1] == 'admin' %}
                                    <span class="btn-disabled">不可删除</span>
                                {% else %}
                                    <a href="/delete_user?id={{ user[0] }}" class="btn-delete" onclick="return confirm('确定删除？')">删除</a>
                                {% endif %}
                            </td>
                        </tr>
                    {% endfor %}
                </tbody>
            </table>
        </div>
    </body>
</html>
"""

# ========== 路由逻辑（保留注入漏洞和admin保护）==========
@app.route('/', methods=['GET', 'POST'])
def login():
    result = None
    success = False
    username = ""
    password = ""

    if request.method == 'POST':
        username = request.form.get('username', '')
        password = request.form.get('password', '')
        sql = f"SELECT * FROM users WHERE username='{username}' AND password='{password}'"
        session['last_sql'] = sql
        conn = sqlite3.connect('test.db')
        c = conn.cursor()
        try:
            c.execute(sql)
            data = c.fetchone()
            if data:
                session['username'] = data[1]
                success = True
                if data[1] == 'admin':
                    return redirect('/admin/dashboard')
                return redirect('/profile')
            result = "用户名或密码错误"
        except Exception as e:
            result = f"错误：{e}"
        conn.close()

    return render_template_string(LOGIN_HTML, result=result, success=success, username=username, password=password)

@app.route('/register', methods=['GET', 'POST'])
def register():
    result = None
    success = False
    username = ""
    password = ""

    if request.method == 'POST':
        username = request.form.get('username', '')
        password = request.form.get('password', '')
        if username.lower() == 'admin':
            result = "该用户名不可用"
            success = False
        else:
            sql = f"INSERT INTO users (username, password) VALUES ('{username}', '{password}')"
            conn = sqlite3.connect('test.db')
            c = conn.cursor()
            try:
                c.execute(sql)
                conn.commit()
                result = "注册成功，请返回登录"
                success = True
            except Exception as e:
                conn.rollback()
                result = f"注册失败：{e}"
            conn.close()

    return render_template_string(REGISTER_HTML, result=result, success=success, username=username, password=password)

@app.route('/profile')
def profile():
    if 'username' not in session:
        return redirect('/')
    username = session.get('username')
    conn = sqlite3.connect('test.db')
    c = conn.cursor()
    c.execute(f"SELECT * FROM users WHERE username='{username}'")
    user_data = c.fetchone()
    conn.close()
    return render_template_string(PROFILE_HTML, username=username, user_data=user_data)

@app.route('/admin/dashboard')
def admin_dashboard():
    if 'username' not in session or session.get('username') != 'admin':
        return redirect('/')
    username = session.get('username')
    current_time = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    conn = sqlite3.connect('test.db')
    c = conn.cursor()
    c.execute("SELECT * FROM users")
    users = c.fetchall()
    conn.close()
    return render_template_string(ADMIN_DASHBOARD_HTML, username=username, users=users, current_time=current_time)

@app.route('/delete_user')
def delete_user():
    if 'username' not in session or session.get('username') != 'admin':
        return redirect('/')
    user_id = request.args.get('id', '')
    conn = sqlite3.connect('test.db')
    c = conn.cursor()
    c.execute(f"SELECT username FROM users WHERE id={user_id}")
    user = c.fetchone()
    if user and user[0] == 'admin':
        conn.close()
        return redirect('/admin/dashboard')
    c.execute(f"DELETE FROM users WHERE id={user_id}")
    conn.commit()
    conn.close()
    return redirect('/admin/dashboard')

@app.route('/logout')
def logout():
    session.clear()
    return redirect('/')

def open_browser():
    import time
    time.sleep(1.5)
    webbrowser.open('http://127.0.0.1:5000')

if __name__ == '__main__':
    threading.Thread(target=open_browser, daemon=True).start()
    app.run(debug=False, port=5000)