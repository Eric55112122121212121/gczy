#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 反码转换函数
string toOnesComplement(int num, int bits)
{
    string result(bits, '0');

    if (num >= 0)
    {
        // 正数：直接转二进制
        for (int i = bits - 1; i >= 0 && num > 0; --i)
        {
            result[i] = (num % 2) + '0';
            num /= 2;
        }
    }
    else
    {
        // 负数：绝对值取二进制后按位取反
        int posNum = abs(num);
        string temp(bits, '0');

        for (int i = bits - 1; i >= 0 && posNum > 0; --i)
        {
            temp[i] = (posNum % 2) + '0';
            posNum /= 2;
        }

        for (int i = 0; i < bits; ++i)
        {
            result[i] = (temp[i] == '0') ? '1' : '0';
        }
    }

    return result;
}

int main()
{
    int num, bits;

    cout << "请输入一个整数: ";
    cin >> num;

    cout << "请输入位数 (8 / 16 / 32): ";
    cin >> bits;

    cout << num << " 的 "
         << bits << " 位反码是: "
         << toOnesComplement(num, bits) << endl;

    return 0;
}
