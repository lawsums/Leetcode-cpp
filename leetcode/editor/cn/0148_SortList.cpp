// 2025-09-10 16:20:05
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Given the head of a linked list, return the list after sorting it in
//ascending order.
//
//
// Example 1:
//
//
//Input: head = [4,2,1,3]
//Output: [1,2,3,4]
//
//
// Example 2:
//
//
//Input: head = [-1,5,3,4,0]
//Output: [-1,0,3,4,5]
//
//
// Example 3:
//
//
//Input: head = []
//Output: []
//
//
//
// Constraints:
//
//
// The number of nodes in the list is in the range [0, 5 * 10⁴].
// -10⁵ <= Node.val <= 10⁵
//
//
//
// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.
//e. constant space)?
//
// Related Topics 链表 双指针 分治 排序 归并排序 👍 2610 👎 0


 #include "../../../include/ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    vector<ListNode*> nums;
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr; // 处理空链表

        ListNode* cur = head;
        while (cur) {
            nums.push_back(cur);
            cur = cur->next;
        }

        MergeSort(nums, 0, nums.size() - 1);

        // 虽然修改了值，但链表连接顺序不变，这是可以的
        return head;
    }

    void MergeSort(vector<ListNode*>& nums, int l, int r) {
        if (l >= r) return;

        int m = l + (r - l) / 2;
        MergeSort(nums, l, m);
        MergeSort(nums, m + 1, r);
        Merge(nums, l, m, r);
    }

    void Merge(vector<ListNode*>& nums, int l, int m, int r) {
        vector<int> tmp;
        int i = l, j = m + 1;

        while (i <= m && j <= r) {
            if (nums[i]->val <= nums[j]->val) {
                tmp.push_back(nums[i++]->val);
            } else {
                tmp.push_back(nums[j++]->val);
            }
        }

        while (i <= m) tmp.push_back(nums[i++]->val);
        while (j <= r) tmp.push_back(nums[j++]->val);

        // 将排序后的值复制回节点
        for (int k = l; k <= r; k++) {
            nums[k]->val = tmp[k - l];
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)
