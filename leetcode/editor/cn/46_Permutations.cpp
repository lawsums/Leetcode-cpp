// 2025-08-30 19:42:11
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given an array nums of distinct integers, return all the possible 
//permutations. You can return the answer in any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
// Example 2: 
// Input: nums = [0,1]
//Output: [[0,1],[1,0]]
// 
// Example 3: 
// Input: nums = [1]
//Output: [[1]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// All the integers of nums are unique. 
// 
//
// Related Topics 数组 回溯 👍 3171 👎 0


// #include "../../../ListOperations.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
    vector<bool> used;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(), false);
        dfs(0, nums);
        return ans;
    }

    void dfs(int step, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (step == nums.size()) {
                ans.push_back(path);
                return;
            }
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);

                dfs(step + 1, nums);

                used[i] = false;
                path.pop_back();
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
