// 2025-09-02 18:24:02
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//English description is not available for the problem. Please switch to 
//Chinese. 
//
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 97 👎 0


// #include "../../../ListOperations.h"
 #include "../../../include/TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    TreeNode* ans = nullptr;
    TreeNode* p;

public:
    void inorder(TreeNode* node, TreeNode*& pre) {
        if (!node) return;

        // 遍历左子树
        inorder(node->left, pre);

        // 访问当前节点
        if (pre == p) {
            ans = node;
        }
        pre = node;
        // 遍历右子树
        inorder(node->right, pre);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        this->p = p;
        TreeNode* pre = nullptr;  // 初始化前驱节点
        inorder(root, pre);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

