//
// Created by Hello on 2025/8/27.
//

#ifndef LEETCODE_LEETCODE_H
#define LEETCODE_LEETCODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#endif//LEETCODE_LEETCODE_H
