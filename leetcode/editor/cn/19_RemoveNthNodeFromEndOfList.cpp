// 2025-08-29 15:27:10
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given the head of a linked list, remove the nᵗʰ node from the end of the list 
//and return its head. 
//
// 
// Example 1: 
// 
// 
//Input: head = [1,2,3,4,5], n = 2
//Output: [1,2,3,5]
// 
//
// Example 2: 
//
// 
//Input: head = [1], n = 1
//Output: []
// 
//
// Example 3: 
//
// 
//Input: head = [1,2], n = 1
//Output: [1]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is sz. 
// 1 <= sz <= 30 
// 0 <= Node.val <= 100 
// 1 <= n <= sz 
// 
//
// 
// Follow up: Could you do this in one pass? 
//
// Related Topics 链表 双指针 👍 3168 👎 0


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

//#include "../../../ListOperations.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int n = length(head);
        ListNode *dummy = new ListNode();
        dummy->next = head;

        // 寻找第n - k个节点
        ListNode *cur = head, *pre = dummy;
        for (int i = 0; i < n - k; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return dummy->next;
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
};
//leetcode submit region end(Prohibit modification and deletion)
