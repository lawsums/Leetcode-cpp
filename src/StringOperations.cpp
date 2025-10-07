#include "../include/StringOperations.h"
#include <algorithm>
#include <iostream>
#include <string>

typedef long long ll;
using namespace std;

string StringOperations::addStrings(string num1, string num2) {
    int carry = 0;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string ans = "";
    for (int i = 0, tmp = 0; i < num1.size() || i < num2.size() || carry; i++) {
        tmp = (i < num1.size() ? (num1[i] - '0') : 0) + (i < num2.size() ? (num2[i] - '0') : 0) + carry;
        ans += (tmp % 10 + '0');
        carry = tmp / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

/* 次数小于10的字符串自加
 * params: num1 待处理的字符串
 * params: times 次数
 * result:
 */
string StringOperations::mulStringsLessTenTimes(string num1, int times) {
    if (times == 0) return "0";
    if (times == 1) return num1;

    string ans = "0";
    for (int i = 0; i < times; i++) {
        ans = addStrings(ans, num1);
    }
    return ans;
}

/* 字符串乘法
 * params: num1 字符串1
 * params: num2 字符串2
 * result: 字符串相乘的结果
 */
string StringOperations::mulStrings(string num1, string num2) {
    // 处理特殊情况
    if (num1 == "0" || num2 == "0") return "0";

    int n = num2.size();
    string ans = "0";

    // 从右往左处理（从低位到高位）
    for (int i = n - 1; i >= 0; i--) {
        int digit = num2[i] - '0';
        if (digit == 0) continue;  // 跳过0，提高效率

        string cur = mulStringsLessTenTimes(num1, digit);

        // 添加适当数量的0（位权）
        int zeros_to_add = n - 1 - i;
        if (zeros_to_add > 0) {
            cur += string(zeros_to_add, '0');
        }

        ans = addStrings(ans, cur);
    }

    return ans;
}


/* 字符串哈希
 * params: [string s] 接收字符串
 * result: 以499为底的字符哈希值
 */
ll StringOperations::string_hash(const string& s) {
    int n = s.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans * base + mapping(s[i]);
    }
    return ans;
}

/* 字符映射,'0'-'9'映射到1-10, 'a'-'z'映射到11-36, 'A'-'Z'映射到37-62
 * params: [char c]
 * result:
 */
int StringOperations::mapping(char c) {
    if (isdigit(c)) {
        return c - '0' + 1;
    } else if ('a' <= c && c <= 'z') {
        return c - 'a' + 11;
    } else if ('A' <= c && c <= 'Z') {
        return c - 'A' + 37;
    }
    // 题目没有要求其他字符
    return -1;
}
