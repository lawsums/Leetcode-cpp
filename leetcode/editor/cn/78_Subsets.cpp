// 2025-08-30 16:45:19
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given an integer array nums of unique elements, return all possible subsets (
//the power set). 
//
// The solution set must not contain duplicate subsets. Return the solution in 
//any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// Example 2: 
//
// 
//Input: nums = [0]
//Output: [[],[0]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// All the numbers of nums are unique. 
// 
//
// Related Topics 位运算 数组 回溯 👍 2536 👎 0


// #include "../../../ListOperations.h"
#include <functional>
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        function<void(int)> dfs = [&](int step) {
            if (step == n) {
                ans.push_back(path);
                return;
            }

            dfs(step + 1);

            path.push_back(nums[step]);
            dfs(step + 1);
            path.pop_back();
        };

        dfs(0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> nums = {1,2,3};
    auto ans = Solution().subsets(nums);
    for (const auto& row : ans) {
        cout << "[";
        if (row.size() == 0) cout << "]" << endl;
        for (int i = 0; i < row.size(); i++) {
            if (i != row.size() - 1) cout << row[i] << ", ";
            else cout << row[i] << "]" << endl;
        }
    }
}