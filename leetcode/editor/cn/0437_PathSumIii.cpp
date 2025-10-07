// 2025-09-05 11:09:30
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given the root of a binary tree and an integer targetSum, return the number 
//of paths where the sum of the values along the path equals targetSum. 
//
// The path does not need to start or end at the root or a leaf, but it must go 
//downwards (i.e., traveling only from parent nodes to child nodes). 
//
// 
// Example 1: 
// 
// 
//Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
//Output: 3
//Explanation: The paths that sum to 8 are shown.
// 
//
// Example 2: 
//
// 
//Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//Output: 3
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 1000]. 
// -10⁹ <= Node.val <= 10⁹ 
// -1000 <= targetSum <= 1000 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 2128 👎 0


// #include "../../../ListOperations.h"
 #include "../../../include/TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#include <unordered_map>
typedef long long ll;

class Solution {
private:
    unordered_map<ll, int> paths;
    int targetSum;
    int ans = 0;

public:
    int pathSum(TreeNode* root, int targetSum) {
        // 使用一个哈希表存储已经出现过的paths
        this->targetSum = targetSum;
        paths[0]++;
        solver(root, 0);
        return ans;
    }

    void solver(TreeNode* node, ll cur_sum) {
        if (!node) return;

        cur_sum += node->val;
        if (paths[cur_sum - targetSum] > 0) { ans += paths[cur_sum - targetSum]; }
        paths[cur_sum]++;


        solver(node->left, cur_sum);
        solver(node->right, cur_sum);

        paths[cur_sum]--;
        return;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
