// 2025-08-29 17:47:20
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//Given the head of a linked list, return the node where the cycle begins. If 
//there is no cycle, return null. 
//
// There is a cycle in a linked list if there is some node in the list that can 
//be reached again by continuously following the next pointer. Internally, pos is 
//used to denote the index of the node that tail's next pointer is connected to (0
//-indexed). It is -1 if there is no cycle. Note that pos is not passed as a 
//parameter. 
//
// Do not modify the linked list. 
//
// 
// Example 1: 
// 
// 
//Input: head = [3,2,0,-4], pos = 1
//Output: tail connects to node index 1
//Explanation: There is a cycle in the linked list, where tail connects to the 
//second node.
// 
//
// Example 2: 
// 
// 
//Input: head = [1,2], pos = 0
//Output: tail connects to node index 0
//Explanation: There is a cycle in the linked list, where tail connects to the 
//first node.
// 
//
// Example 3: 
// 
// 
//Input: head = [1], pos = -1
//Output: no cycle
//Explanation: There is no cycle in the linked list.
// 
//
// 
// Constraints: 
//
// 
// The number of the nodes in the list is in the range [0, 10⁴]. 
// -10⁵ <= Node.val <= 10⁵ 
// pos is -1 or a valid index in the linked-list. 
// 
//
// 
// Follow up: Can you solve it using O(1) (i.e. constant) memory? 
//
// Related Topics 哈希表 链表 双指针 👍 2861 👎 0


#include "../../../include/ListOperations.h"
#include <unordered_map>
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        return f1(head);
//        return f2(head);
    }

    // 哈希表
    ListNode* f1(ListNode *head) {
        // 用哈希表记录出现的坐标
        unordered_map<ListNode*, int> mp;
        ListNode* cur = head;
        int index = 0;
        while (cur) {
            if (mp.count(cur)) {
                return cur;
            }
            mp[cur] = index++;
            cur = cur->next;
        }
        return nullptr;
    }

    // 快慢指针

};
//leetcode submit region end(Prohibit modification and deletion)
