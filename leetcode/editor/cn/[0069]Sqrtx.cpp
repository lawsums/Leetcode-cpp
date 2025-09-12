// 2025-09-11 16:46:26
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given a non-negative integer x, return the square root of x rounded down to 
//the nearest integer. The returned integer should be non-negative as well. 
//
// You must not use any built-in exponent function or operator. 
//
// 
// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python. 
// 
//
// 
// Example 1: 
//
// 
//Input: x = 4
//Output: 2
//Explanation: The square root of 4 is 2, so we return 2.
// 
//
// Example 2: 
//
// 
//Input: x = 8
//Output: 2
//Explanation: The square root of 8 is 2.82842..., and since we round it down 
//to the nearest integer, 2 is returned.
// 
//
// 
// Constraints: 
//
// 
// 0 <= x <= 2³¹ - 1 
// 
//
// Related Topics 数学 二分查找 👍 1707 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        return f2(x);
    }

    int f1(int x) {
        // 找到第一个 m * m <= x 而 (m + 1) * (m + 1) > x的元素
        if (x == 0 || x == 1) return x;

        int l = 1, r = x - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (1LL * m * m == x) {
                return m;
            } else if (1LL * m * m > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l - 1;
    }

    int f2(int x) {
        // 找到第一个 m * m <= x 而 (m + 1) * (m + 1) > x的元素
        if (x == 0 || x == 1) return x;

        int l = 1, r = x - 1, res = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (1LL * m * m <= x) {
                l = m + 1;
                res = m;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
