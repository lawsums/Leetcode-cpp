// 2025-08-27 16:44:02
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
// Related Topics 递归 链表 👍 220 👎 0


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
