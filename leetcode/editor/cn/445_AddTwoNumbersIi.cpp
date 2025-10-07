// 2025-08-27 17:01:01
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//You are given two non-empty linked lists representing two non-negative 
//integers. The most significant digit comes first and each of their nodes contains a 
//single digit. Add the two numbers and return the sum as a linked list. 
//
// You may assume the two numbers do not contain any leading zero, except the 
//number 0 itself. 
//
// 
// Example 1: 
// 
// 
//Input: l1 = [7,2,4,3], l2 = [5,6,4]
//Output: [7,8,0,7]
// 
//
// Example 2: 
//
// 
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [8,0,7]
// 
//
// Example 3: 
//
// 
//Input: l1 = [0], l2 = [0]
//Output: [0]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in each linked list is in the range [1, 100]. 
// 0 <= Node.val <= 9 
// It is guaranteed that the list represents a number that does not have 
//leading zeros. 
// 
//
// 
// Follow up: Could you solve it without reversing the input lists? 
//
// Related Topics 栈 链表 数学 👍 779 👎 0


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
//#include "Leetcode.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         l1 = reverseList(l1);
         l2 = reverseList(l2);
         return reverseList(addTwoNumber(l1, l2));
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

    ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
        int carry = 0;
        auto* dummy = new ListNode();
        auto* cur = dummy;
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(carry % 10);
            cur = cur->next;
            carry /= 10;
        }
        return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
