// 2025-09-01 20:07:07
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given the root of a binary tree, return the leftmost value in the last row of 
//the tree. 
//
// 
// Example 1: 
// 
// 
//Input: root = [2,1,3]
//Output: 1
// 
//
// Example 2: 
// 
// 
//Input: root = [1,2,3,4,null,5,6,null,null,7]
//Output: 7
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 10⁴]. 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 641 👎 0


// #include "../../../ListOperations.h"
 #include "../../../include/TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#include <queue>
class Solution {
private:
    vector<int> ans;
    vector<bool> visited;
public:
    // 层次遍历
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int depth = 0;
        q.push(root);
        while (!q.empty()) {
            int cur_size = q.size();
            for (int i = 0; i < cur_size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                // 加入这个值
                if (ans.size() < depth + 1) {
                    ans.resize(depth + 1, 0);
                    visited.resize(depth + 1, false);
                }
                if (!visited[depth]) {
                    visited[depth] = true;
                    ans[depth] = cur->val;
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            depth++;
        }
        return ans.back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
