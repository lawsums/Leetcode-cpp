// 2025-08-30 17:05:30
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given two integers n and k, return all possible combinations of k numbers 
//chosen from the range [1, n]. 
//
// You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: n = 4, k = 2
//Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
//Explanation: There are 4 choose 2 = 6 total combinations.
//Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to 
//be the same combination.
// 
//
// Example 2: 
//
// 
//Input: n = 1, k = 1
//Output: [[1]]
//Explanation: There is 1 choose 1 = 1 total combination.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// Related Topics 回溯 👍 1794 👎 0


// #include "../../../ListOperations.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    int N, K;
    vector<int> path;
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        N = n, K = k;
        dfs(0, 0);
        return ans;
    }

    void dfs(int begin, int step) {
        if (step == K) {
            ans.push_back(path);
            return;
        }
        for (int i = begin; i < N; i++) {
            path.push_back(i + 1);
            dfs(i + 1, step + 1);
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
