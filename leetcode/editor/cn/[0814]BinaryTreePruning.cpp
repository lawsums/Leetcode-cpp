// 2025-09-05 10:40:22
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given the root of a binary tree, return the same tree where every subtree (of 
//the given tree) not containing a 1 has been removed. 
//
// A subtree of a node node is node plus every node that is a descendant of 
//node. 
//
// 
// Example 1: 
// 
// 
//Input: root = [1,null,0,0,1]
//Output: [1,null,0,null,1]
//Explanation: 
//Only the red nodes satisfy the property "every subtree not containing a 1".
//The diagram on the right represents the answer.
// 
//
// Example 2: 
// 
// 
//Input: root = [1,0,1,0,0,0,1]
//Output: [1,null,1,null,1]
// 
//
// Example 3: 
// 
// 
//Input: root = [1,1,0,1,1,0,1,0]
//Output: [1,1,0,1,1,null,1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 200]. 
// Node.val is either 0 or 1. 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 394 👎 0


// #include "../../../ListOperations.h"
 #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // 如果当前节点是叶子节点且值为0，则修剪掉
        if (root->val == 0 && !root->left && !root->right) {
            return nullptr;
        }

        return root;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    Solution().pruneTree(root);
}