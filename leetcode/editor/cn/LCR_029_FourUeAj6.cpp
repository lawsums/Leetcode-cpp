// 2025-08-29 23:30:52
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

#include <unordered_map>
class Solution {
public:
    Node *insert(Node *root, int insertVal) {
        return f1(root, insertVal);
    }

    Node* f1(Node* head, int insertVal) {
        if (!head) {
            auto p = new Node(insertVal);
            p->next = p;
            return p;
        }
        auto tmp = head;
        for (; tmp->next != head && tmp->next->val >= tmp->val; tmp = tmp->next);
        auto p = tmp;
        for (; p->next != tmp && p->next->val < insertVal; p = p->next);
        if (p->next->val < insertVal) p = p->next;
        p->next = new Node(insertVal, p->next);
        return head;
    }

    Node *f2(Node *root, int insertVal) {
        auto insert = [](Node* pre, Node* cur, int val) {
            Node *new_node = new Node(val);
            pre->next = new_node;
            new_node->next = cur;
        };

        Node *dummy = new Node();
        Node *pre = dummy, *cur = root;

        if (!root) {
            Node *new_node = new Node(insertVal);
            new_node->next = new_node;
            return new_node;
        }

        unordered_map<int, int> mp;
        int n = length(root, mp);
        if (n == 1 || mp.size() == 1) {
            insert(root, root->next, insertVal);
            return root;
        }

        while (pre->val <= cur->val) {
            pre = cur;
            cur = cur->next;
        }// 找到分界点

        if (insertVal < cur->val || insertVal > pre->val) {
            insert(pre, cur, insertVal);
            return root;
        }

        Node *head = cur;
        while (cur->next != head) {
            pre = cur;
            cur = cur->next;
            if (pre->val <= insertVal && insertVal <= cur->val) {
                insert(pre, cur, insertVal);
                break;
            }
        }

        return root;
    }

private:
    int length(Node *root, unordered_map<int, int> &mp) {
        unordered_map<Node *, int> if_exist;
        Node *cur = root;
        int ans = 0;
        while (cur) {
            if (if_exist.count(cur)) return ans;
            if_exist[cur]++;
            mp[cur->val]++;
            ans++;
            cur = cur->next;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

