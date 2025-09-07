// 2025-09-07 23:40:50
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given an integer n, return any array containing n unique integers such that 
//they add up to 0. 
//
// 
// Example 1: 
//
// 
//Input: n = 5
//Output: [-7,-1,1,3,4]
//Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
// 
//
// Example 2: 
//
// 
//Input: n = 3
//Output: [-1,0,1]
// 
//
// Example 3: 
//
// 
//Input: n = 1
//Output: [0]
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 1000 
// 
//
// Related Topics 数组 数学 👍 105 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int times = n / 2;
        for (int i = 0; i < times; i++) {
            int tmp = i + 1;
            ans.push_back(tmp);
            ans.push_back(-tmp);
        }

        if (n % 2 == 1) {
            ans.push_back(0);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
