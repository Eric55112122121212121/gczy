#pragma execution_character_set("utf-8")
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstdio>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}

string getWebsiteInput() {
    string website;
    int attempt = 0;

    while (attempt < 3) {
        cout << "1. 请输入要举报的网址: ";
        getline(cin, website);

        website.erase(0, website.find_first_not_of(" \t"));
        website.erase(website.find_last_not_of(" \t") + 1);

        if (website.empty()) {
            cout << "错误：网址不能为空，请重新输入\n\n";
            attempt++;
            continue;
        }

        if (website.find(".") == string::npos) {
            cout << "注意：网址格式可能不正确，是否继续？(y/n): ";
            string confirm;
            getline(cin, confirm);
            if (confirm != "y" && confirm != "Y") {
                cout << "请重新输入网址\n\n";
                continue;
            }
        }
        return website;
    }

    cout << "输入次数超限，使用默认网址\n";
    return "https://example.com";
}

int getReportType() {
    int typeChoice = 0;
    string input;

    while (true) {
        cout << "\n2. 请选择举报类型:\n";
        cout << "   [1] 违法信息\n";
        cout << "   [2] 侵权内容\n";
        cout << "   [3] 网络诈骗\n";
        cout << "   [4] 其他违规\n";
        cout << "请选择(1-4): ";

        getline(cin, input);

        if (input.empty()) {
            cout << "错误：请输入选择编号\n";
            continue;
        }

        bool isNumber = true;
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            cout << "错误：请输入数字 1-4\n";
            continue;
        }

        typeChoice = atoi(input.c_str());
        if (typeChoice < 1 || typeChoice > 4) {
            cout << "错误：请输入 1-4 之间的数字\n";
            continue;
        }
        break;
    }
    return typeChoice;
}

string getReportReason() {
    string reason;
    while (true) {
        cout << "\n3. 请输入举报理由: ";
        getline(cin, reason);

        if (reason.empty()) {
            cout << "错误：举报理由不能为空\n";
            continue;
        }

        if (reason.length() < 5) {
            cout << "注意：理由过短，建议详细描述。是否继续？(y/n): ";
            string confirm;
            getline(cin, confirm);
            if (confirm != "y" && confirm != "Y") continue;
        }
        break;
    }
    return reason;
}

string getEvidence() {
    cout << "\n4. 请输入相关证据（空行结束，最多20条）:\n";

    string evidence;
    string line;
    int count = 0;
    const int MAX_LINES = 20;

    while (count < MAX_LINES) {
        cout << "  " << count + 1 << ". ";
        getline(cin, line);
        if (line.empty()) break;

        char numBuf[10];
        sprintf_s(numBuf, sizeof(numBuf), "%d", count + 1);
        evidence += "  ";
        evidence += numBuf;
        evidence += ". ";
        evidence += line;
        evidence += "\n";

        count++;
    }

    if (evidence.empty()) return "  暂无证据\n";
    return evidence;
}

string getContactInfo() {
    cout << "\n5. 请输入您的联系方式（可选）: ";
    string contact;
    getline(cin, contact);
    contact.erase(0, contact.find_first_not_of(" \t"));
    contact.erase(contact.find_last_not_of(" \t") + 1);
    return contact;
}

void showSummary(const string& website, int typeChoice,
                 const string& reason, const string& evidence,
                 const string& contact) {
    cout << "\n==================== 举报信息汇总 ====================\n";
    cout << "举报网址: " << website << endl;

    string typeStr[] = {"", "违法信息", "侵权内容", "网络诈骗", "其他违规"};
    cout << "举报类型: " << typeStr[typeChoice] << endl;
    cout << "举报理由: " << reason << endl;
    cout << "相关证据:\n" << evidence;

    if (!contact.empty())
        cout << "联系方式: " << contact << endl;

    cout << "=====================================================\n";
}

bool confirmSave() {
    string confirm;
    while (true) {
        cout << "\n是否保存举报信息到文件？(y/n): ";
        getline(cin, confirm);
        if (confirm == "y" || confirm == "Y") return true;
        if (confirm == "n" || confirm == "N") return false;
        cout << "错误：请输入 y 或 n\n";
    }
}

string generateFilename() {
    time_t now = time(NULL);
    tm timeinfo;
    localtime_s(&timeinfo, &now);
    char buf[100];
    strftime(buf, sizeof(buf), "report_%Y%m%d_%H%M%S.txt", &timeinfo);
    return string(buf);
}

bool saveToFile(const string& filename, const string& website, int typeChoice,
                const string& reason, const string& evidence, const string& contact) {
    ofstream file(filename.c_str());
    if (!file) return false;

    time_t now = time(NULL);
    tm t;
    localtime_s(&t, &now);
    char timeStr[50];
    strftime(timeStr, sizeof(timeStr), "%Y年%m月%d日 %H:%M:%S", &t);

    file << "============= 网站举报信息 ============\n";
    file << "生成时间: " << timeStr << "\n\n";

    file << "【举报网址】\n" << website << "\n\n";

    string typeStr[] = {"", "违法信息", "侵权内容", "网络诈骗", "其他违规"};
    file << "【举报类型】\n" << typeStr[typeChoice] << "\n\n";

    file << "【举报理由】\n" << reason << "\n\n";
    file << "【相关证据】\n" << evidence << "\n";

    if (!contact.empty())
        file << "【联系方式】\n" << contact << "\n\n";

    file << "======================================\n";
    file << "官方举报平台：https://www.12377.cn\n";
    file << "请自行前往提交举报\n";

    file.close();
    return true;
}

int main() {
    cout << "============ 网站举报工具 v2.0 ============\n";
    cout << "  本工具仅整理信息，不自动提交举报\n";
    cout << "  请务必前往官方平台：12377.cn 提交\n";
    cout << "==========================================\n\n";

    string website = getWebsiteInput();
    int type = getReportType();
    string reason = getReportReason();
    string evidence = getEvidence();
    string contact = getContactInfo();

    showSummary(website, type, reason, evidence, contact);

    if (!confirmSave()) {
        cout << "\n已取消保存。\n按回车退出...";
        cin.get();
        return 0;
    }

    string filename = generateFilename();
    bool ok = saveToFile(filename, website, type, reason, evidence, contact);

    if (ok) {
        cout << "\n保存成功！文件：" << filename << endl;
    } else {
        cout << "\n保存失败！\n";
    }

    cout << "\n按回车退出...";
    cin.get();

    return 0;
}