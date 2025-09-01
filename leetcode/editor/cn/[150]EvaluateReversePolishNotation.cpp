// 2025-09-01 12:19:52
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//You are given an array of strings tokens that represents an arithmetic 
//expression in a Reverse Polish Notation. 
//
// Evaluate the expression. Return an integer that represents the value of the 
//expression. 
//
// Note that: 
//
// 
// The valid operators are '+', '-', '*', and '/'. 
// Each operand may be an integer or another expression. 
// The division between two integers always truncates toward zero. 
// There will not be any division by zero. 
// The input represents a valid arithmetic expression in a reverse polish 
//notation. 
// The answer and all the intermediate calculations can be represented in a 32-
//bit integer. 
// 
//
// 
// Example 1: 
//
// 
//Input: tokens = ["2","1","+","3","*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9
// 
//
// Example 2: 
//
// 
//Input: tokens = ["4","13","5","/","+"]
//Output: 6
//Explanation: (4 + (13 / 5)) = 6
// 
//
// Example 3: 
//
// 
//Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
//Output: 22
//Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22
// 
//
// 
// Constraints: 
//
// 
// 1 <= tokens.length <= 10⁴ 
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the 
//range [-200, 200]. 
// 
//
// Related Topics 栈 数组 数学 👍 1027 👎 0


// #include "../../../ListOperations.h"
// #include "../../../StringOperations.h"
 #include "../../../DisplayHelper.h"

#include <stack>
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stk;

        for (const auto& token : tokens) {
            if (isdigit(token[0]) || (token.size() != 1 && token[0] == '-')) {
                stk.emplace_back(token[0] == '-' ? -stoi(token.substr(1)) : stoi(token));
            } else {
                int op2 = stk.back(); stk.pop_back();
                int op1 = stk.back(); stk.pop_back();
                if (token == "+") {
                    stk.emplace_back(op1 + op2);
                } else if (token == "-") {
                    stk.emplace_back(op1 - op2);
                } else if (token == "*") {
                    stk.emplace_back(op1 * op2);
                } else if (token == "/") {
                    stk.emplace_back(op1 / op2);
                }
            }
            DisplayHelper::display(DisplayHelper::DisplayConfig{", "}, stk);
        }

        return stk.back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution().evalRPN(tokens);
}