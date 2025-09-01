// 2025-09-01 19:58:22
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given the root of a binary tree, return an array of the largest value in each 
//row of the tree (0-indexed). 
//
// 
// Example 1: 
// 
// 
//Input: root = [1,3,2,5,3,null,9]
//Output: [1,3,9]
// 
//
// Example 2: 
//
// 
//Input: root = [1,2,3]
//Output: [1,3]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree will be in the range [0, 10⁴]. 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 403 👎 0


// #include "../../../ListOperations.h"
#include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> ans;

public:
    void preorder(TreeNode* node, int depth) {
        if (!node) return;
        if (ans.size() < depth + 1) {
            ans.resize(depth + 1, INT_MIN);
        }
        ans[depth] = max(ans[depth], node->val);
        preorder(node->left, depth + 1);
        preorder(node->right, depth + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        preorder(root, 0);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
