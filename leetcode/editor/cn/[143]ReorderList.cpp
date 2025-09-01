// 2025-08-29 17:59:00
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

//You are given the head of a singly linked-list. The list can be represented
//as:
//
//
//L0 → L1 → … → Ln - 1 → Ln
//
//
// Reorder the list to be on the following form:
//
//
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//
//
// You may not modify the values in the list's nodes. Only nodes themselves may
//be changed.
//
//
// Example 1:
//
//
//Input: head = [1,2,3,4]
//Output: [1,4,2,3]
//
//
// Example 2:
//
//
//Input: head = [1,2,3,4,5]
//Output: [1,5,2,4,3]
//
//
//
// Constraints:
//
//
// The number of nodes in the list is in the range [1, 5 * 10⁴].
// 1 <= Node.val <= 1000
//
//
// Related Topics 栈 递归 链表 双指针 👍 1621 👎 0


#include "../../../ListOperations.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void reorderList(ListNode *head) {
        f2(head);
    }

    // time: O(N) space: O(N)
    void f1(ListNode *head) {
        vector<ListNode *> vec;
        ListNode *cur = head, *pre = nullptr;
        while (cur) {
            vec.push_back(cur);
            cur = cur->next;
        }

        // 加入列表之后通过左右指针重排序
        int l = 0, r = vec.size() - 1;
        while (l < r) {
            vec[l++]->next = vec[r];
            if (l < r) vec[r--]->next = vec[l];// 多一层判断防止成环
        }
        vec[r]->next = nullptr;
    }

    // time: O(n) space: O(1)
    void f2(ListNode *head) {
        if (!head || !head->next) return;

        ListNode* mid = mid_l(head);
        ListNode* A = head;
        ListNode* B = mid->next;
        mid->next = nullptr; /*
 *      这里非常重要!!!!!!!!!!!!!!!!!!!!!!!
 *      这里起到了隔断原先的两个链表的关系的作用
 *
 * */
        B = reverseList(B);

        ListNode *a_next, *b_next;
        while (A && B) {
            a_next = A->next;
            b_next = B->next;

            A->next = B;
            B->next = a_next;

            A = a_next;
            B = b_next;
        }
        // 此时 A 指向原链表的最后一个节点或 nullptr，B 为 nullptr
        // 链表已正确连接，无需额外设置 next
    }
    
private:
    int length(ListNode* root) {
        auto *cur = root;
        int ans = 0;
        while (cur) {
            ans++;
            cur = cur->next;
        }
        return ans;
    }
    
    ListNode* mid_l(ListNode* head) {
        int n = length(head), cnt = 0; 
        int id = n / 2;
        ListNode* cur = head;
        while (cnt != id) {
            cur = cur->next;
            cnt++;
        }
        return cur;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head, *nxt = nullptr;
        while (cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
