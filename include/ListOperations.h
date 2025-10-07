#ifndef LEETCODE_LISTOPERATIONS_H
#define LEETCODE_LISTOPERATIONS_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ListOperations {
public:
    // 全部改为静态方法
    static int length(ListNode *root);
    static ListNode *mid_l(ListNode *head);
    static ListNode *mid_r(ListNode *head);
    static ListNode *tail(ListNode *root);
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    static ListNode *reverseList(ListNode *head);
    static ListNode *addTwoNumbers_reversed(ListNode *l1, ListNode *l2);
    static ListNode *circleOrderedListTail(ListNode *root);
    static ListNode *circleOrderedListHead(ListNode *root);

    // 禁止实例化（可选）
    ListOperations() = delete;
    ~ListOperations() = delete;
};

#endif// LEETCODE_LISTOPERATIONS_H