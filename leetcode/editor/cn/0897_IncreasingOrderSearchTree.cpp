// 2025-09-08 12:12:29
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given the root of a binary search tree, rearrange the tree in in-order so 
//that the leftmost node in the tree is now the root of the tree, and every node has 
//no left child and only one right child. 
//
// 
// Example 1: 
// 
// 
//Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
//Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
// 
//
// Example 2: 
// 
// 
//Input: root = [5,1,7]
//Output: [1,null,5,null,7]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the given tree will be in the range [1, 100]. 
// 0 <= Node.val <= 1000 
// 
//
// Related Topics 栈 树 深度优先搜索 二叉搜索树 二叉树 👍 362 👎 0


// #include "../../../ListOperations.h"
 #include "../../../include/TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<TreeNode*> ordered_nodes;
    TreeNode* pre = nullptr;
    TreeNode* leftmost = nullptr;


public:
//    void inorder(TreeNode* node) {
//        if (!node) return;
//
//        inorder(node->left);
//        ordered_nodes.push_back(node);
//        inorder(node->right);
//    }

    TreeNode* increasingBST(TreeNode* root) {
        return f2(root);
    }

    // O(n) O(n)
    // 基础做法
    TreeNode* f1(TreeNode* root) {
        // 递归 lambda 函数（需要捕获自身引用）
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            ordered_nodes.push_back(node);
            inorder(node->right);
        };

        inorder(root);

        for (int i = 0; i < ordered_nodes.size(); i++) {
            ordered_nodes[i]->left  = nullptr;
            if (i != ordered_nodes.size() - 1)
                ordered_nodes[i]->right = ordered_nodes[i + 1];
            else
                ordered_nodes[i]->right = nullptr;
        }
        return ordered_nodes[0];
    }

    // O(n) O(n)
    // 优化存储所有节点的数组空间
    TreeNode* f2(TreeNode* root) {
        // 递归 lambda 函数（需要捕获自身引用）
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);

            if (!pre) {
                leftmost = node;
            } else {
                pre->left  = nullptr;
                pre->right = node;
            }
            pre = node;

            inorder(node->right);
        };

        inorder(root);
        pre->left  = nullptr;
        pre->right = nullptr;
        return leftmost;
    }

    // O(n) O(1)
    // 优化递归栈空间
    TreeNode* f3(TreeNode* root) {
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            // TODO 迭代实现inorder函数
        };

        inorder(root);
        pre->left  = nullptr;
        pre->right = nullptr;
        return leftmost;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
