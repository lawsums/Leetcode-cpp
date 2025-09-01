// 2025-08-30 19:12:56
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given a collection of candidate numbers (candidates) and a target number (
//target), find all unique combinations in candidates where the candidate numbers sum 
//to target. 
//
// Each number in candidates may only be used once in the combination. 
//
// Note: The solution set must not contain duplicate combinations. 
//
// 
// Example 1: 
//
// 
//Input: candidates = [10,1,2,7,6,1,5], target = 8
//Output: 
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]
// 
//
// Example 2: 
//
// 
//Input: candidates = [2,5,2,1,2], target = 5
//Output: 
//[
//[1,2,2],
//[5]
//]
// 
//
// 
// Constraints: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// Related Topics 数组 回溯 👍 1703 👎 0


// #include "../../../ListOperations.h"
//leetcode submit region begin(Prohibit modification and deletion)
#include <unordered_map>
typedef unsigned long long ull;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
    unordered_map<ull, int> mp;
    int base = 51;
    // 1 <= candidates[i] <= 50
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        dfs(0, candidates, target);
        return ans;
    }

    void dfs(int begin, vector<int>& candidates, int target) {
        if (target <= 0) {
            ull tmp = hash(path);
            if (target == 0 && !mp.count(tmp)) {
                mp[tmp]++;
                ans.push_back(path);
            }
            return;
        }
        if (begin >= candidates.size()) return;

        for (int i = begin; i < candidates.size(); i++) { // 通过begin来去重
            path.push_back(candidates[i]);
            dfs(i + 1, candidates, target - candidates[i]);
            path.pop_back();
        }
    }
    
private:
    ull hash(vector<int>& path) {
        ull res = 0;
        for (const auto& elem : path) {
            res = res * base + elem;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution().combinationSum2(candidates, target);
}