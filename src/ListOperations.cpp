#include "../include/ListOperations.h"

int ListOperations::length(ListNode *root) {
    auto *cur = root;
    int ans = 0;
    while (cur) {
        ans++;
        cur = cur->next;
    }
    return ans;
}

ListNode *ListOperations::mid_l(ListNode *head) {
    int n = length(head), cnt = 0;
    int id = n / 2;
    ListNode *cur = head;
    while (cnt != id) {
        cur = cur->next;
        cnt++;
    }
    return cur;
}

ListNode *ListOperations::mid_r(ListNode *head) {
    int n = length(head), cnt = 0;
    int id = (n + 1) / 2;
    ListNode *cur = head;
    while (cnt != id) {
        cur = cur->next;
        cnt++;
    }
    return cur;
}

ListNode *ListOperations::reverseList(ListNode *head) {
    ListNode *pre = nullptr, *cur = head, *nxt = nullptr;
    while (cur) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

// 给非循环链表使用的取结尾节点操作
ListNode *ListOperations::tail(ListNode *root) {
    ListNode *cur = root;
    while (cur->next != nullptr) { cur = cur->next; }
    return cur;
}

ListNode *ListOperations::addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    auto *dummy = new ListNode();
    auto *cur = dummy;
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

ListNode *ListOperations::addTwoNumbers_reversed(ListNode *l1, ListNode *l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    ListNode *result = addTwoNumbers(l1, l2);
    // 可选：恢复原链表（如果需要保持输入不变）
    // reverseList(l1);
    // reverseList(l2);
    return reverseList(result);
}

ListNode *ListOperations::circleOrderedListTail(ListNode *root) {
    auto tmp = root;
    for (; tmp->next != root && tmp->next->val >= tmp->val; tmp = tmp->next)
        ;
    return tmp;
}

ListNode *ListOperations::circleOrderedListHead(ListNode *root) {
    return circleOrderedListTail(root)->next;
}
