// 2025-09-04 17:43:16
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//A complete binary tree is a binary tree in which every level, except possibly 
//the last, is completely filled, and all nodes are as far left as possible. 
//
// Design an algorithm to insert a new node to a complete binary tree eeping
//it complete after the insertion. 
//
// Implement the CBTInserter class: 
//
// 
// CBTInserter(TreeNode root) Initializes the data structure with the root of 
//the complete binary tree. 
// int insert(int v) Inserts a TreeNode into the tree with value Node.val == 
//val so that the tree remains complete, and returns the value of the parent of the 
//inserted TreeNode. 
// TreeNode get_root() Returns the root node of the tree. 
// 
//
// 
// Example 1: 
// 
// 
//Input
//["CBTInserter", "insert", "insert", "get_root"]
//[[[1, 2]], [3], [4], []]
//Output
//[null, 1, 2, [1, 2, 3, 4]]
// 
//
//Explanation
//CBTInserter cBTInserter = new CBTInserter([1, 2]);
//cBTInserter.insert(3); // return 1
//cBTInserter.insert(4); // return 2
//cBTInserter.get_root(); // return [1, 2, 3, 4]
//
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree will be in the range [1, 1000]. 
// 0 <= Node.val <= 5000 
// root is a complete binary tree. 
// 0 <= val <= 5000 
// At most 10⁴ calls will be made to insert and get_root. 
// 
//
// Related Topics 树 广度优先搜索 设计 二叉树 👍 181 👎 0


// #include "../../../ListOperations.h"
 #include "../../../include/TreeOperations.h"
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
class CBTInserter {
private:
    TreeNode* root;
    int logicalSize = 0;

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        logicalSize = countSize(root);
    }
    
    int insert(int val) {
        // 把路径拆解成序列
        string road = to_string(logicalSize + 1);
        int n = road.size();
        logicalSize++;
        auto insert_direction = road[n - 1];
        auto cur = root;
        for (int i = 0; i < n - 1; i++) {
            if (road[i] == '0') {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        int ans = cur->val;
        if (insert_direction == '0') {
            cur->left = new TreeNode(val);
        } else {
            cur->right = new TreeNode(val);
        }
        return ans;
    }
    
    TreeNode* get_root() {
        return root;
    }

private:
    int countSize(TreeNode* node) {
        if (!node) return 0;
        int ans = 1;
        if (node->left) ans += countSize(node->left);
        if (node->right) ans += countSize(node->right);
        return ans;
    }

    string to_string(int index) {
        string ans = "";
        while (index != 1) {
            ans += ('0' + (index % 2));
            index = index / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
//leetcode submit region end(Prohibit modification and deletion)
