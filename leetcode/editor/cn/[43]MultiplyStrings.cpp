// 2025-08-27 16:26:14
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given two non-negative integers num1 and num2 represented as strings, return 
//the product of num1 and num2, also represented as a string. 
//
// Note: You must not use any built-in BigInteger library or convert the inputs 
//to integer directly. 
//
// 
// Example 1: 
// Input: num1 = "2", num2 = "3"
//Output: "6"
// 
// Example 2: 
// Input: num1 = "123", num2 = "456"
//Output: "56088"
// 
// 
// Constraints: 
//
// 
// 1 <= num1.length, num2.length <= 200 
// num1 and num2 consist of digits only. 
// Both num1 and num2 do not contain any leading zero, except the number 0 
//itself. 
// 
//
// Related Topics 数学 字符串 模拟 👍 1442 👎 0




//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string multiply(string num1, string num2) {
        return mulStrings(num1, num2);
    }

    string addStrings(string num1, string num2) {
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

    string mulStringsLessTenTimes(string num1, int times) {
        if (times == 0) return "0";
        if (times == 1) return num1;

        string ans = "0";
        for (int i = 0; i < times; i++) {
            ans = addStrings(ans, num1);
        }
        return ans;
    }

    string mulStrings(string num1, string num2) {
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
};
//leetcode submit region end(Prohibit modification and deletion)
