// 2025-08-30 00:13:38
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

//Given the head of a singly linked list, return true if it is a palindrome or
//false otherwise.
//
//
// Example 1:
//
//
//Input: head = [1,2,2,1]
//Output: true
//
//
// Example 2:
//
//
//Input: head = [1,2]
//Output: false
//
//
//
// Constraints:
//
//
// The number of nodes in the list is in the range [1, 10⁵].
// 0 <= Node.val <= 9
//
//
//
//Follow up: Could you do it in
//O(n) time and
//O(1) space?
//
// Related Topics 栈 递归 链表 双指针 👍 2110 👎 0


#include "../../../ListOperations.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        return f2(head);
    }

    // O(n) O(n)
    bool f1(ListNode *head) {
        if (!head) return true;

        ListNode *cur = head;
        vector<int> values;
        while (cur) {
            values.push_back(cur->val);
            cur = cur->next;
        }
        cur = head;
        for (int i = values.size() - 1; i >= 0; i--) {
            if (values[i] != cur->val) {
                return false;
            }
            cur = cur->next;
        }
        return true;
    }

    // O(n) O(1)
    bool f2(ListNode *head) {
        if (!head) return true;

        ListNode *B = mid_l(head);
        B = reverseList(B);

        ListNode *A = head;
        while (A != B && !(A->next == B && A->val == B->val)) {// 此时不满足偶数个节点的情况
            if (A->val != B->val) return false;
            A = A->next;
            B = B->next;
        }
        return true;
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

    ListNode *mid_l(ListNode *head) {
        int n = length(head), cnt = 0;
        int id = n / 2;
        ListNode *cur = head;
        while (cnt != id) {
            cur = cur->next;
            cnt++;
        }
        return cur;
    }

    ListNode *reverseList(ListNode *head) {
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
