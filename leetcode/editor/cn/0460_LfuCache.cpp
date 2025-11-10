// 2025-11-02 14:21:29
#include <bits/stdc++.h>
#include <DisplayHelper.h>
#include <Heap.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//Design and implement a data structure for a Least Frequently Used (LFU) cache.
// 
//
// Implement the LFUCache class: 
//
// 
// LFUCache(int capacity) Initializes the object with the capacity of the data 
//structure. 
// int get(int key) Gets the value of the key if the key exists in the cache. 
//Otherwise, returns -1. 
// void put(int key, int value) Update the value of the key if present, or 
//inserts the key if not already present. When the cache reaches its capacity, it 
//should invalidate and remove the least frequently used key before inserting a new 
//item. For this problem, when there is a tie (i.e., two or more keys with the same 
//frequency), the least recently used key would be invalidated. 
// 
//
// To determine the least frequently used key, a use counter is maintained for 
//each key in the cache. The key with the smallest use counter is the least 
//frequently used key. 
//
// When a key is first inserted into the cache, its use counter is set to 1 (
//due to the put operation). The use counter for a key in the cache is incremented 
//either a get or put operation is called on it. 
//
// The functions get and put must each run in O(1) average time complexity. 
//
// 
// Example 1: 
//
// 
//Input
//["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", 
//"get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
//Output
//[null, null, null, 1, null, -1, 3, null, -1, 3, 4]
//
//Explanation
//// cnt(x) = the use counter for key x
//// cache=[] will show the last used order for tiebreakers (leftmost element 
//is  most recent)
//LFUCache lfu = new LFUCache(2);
//lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
//lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
//lfu.get(1);      // return 1
//                 // cache=[1,2], cnt(2)=1, cnt(1)=2
//lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, 
//invalidate 2.
//                 // cache=[3,1], cnt(3)=1, cnt(1)=2
//lfu.get(2);      // return -1 (not found)
//lfu.get(3);      // return 3
//                 // cache=[3,1], cnt(3)=2, cnt(1)=2
//lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1
//.
//                 // cache=[4,3], cnt(4)=1, cnt(3)=2
//lfu.get(1);      // return -1 (not found)
//lfu.get(3);      // return 3
//                 // cache=[3,4], cnt(4)=1, cnt(3)=3
//lfu.get(4);      // return 4
//                 // cache=[4,3], cnt(4)=2, cnt(3)=3
// 
//
// 
// Constraints: 
//
// 
// 1 <= capacity <= 10⁴ 
// 0 <= key <= 10⁵ 
// 0 <= value <= 10⁹ 
// At most 2 * 10⁵ calls will be made to get and put. 
// 
//
// 
// 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 892 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class LFUCache {
private:
    struct Node {
        int key, val, freq;
        Node(int k, int v, int f) : key(k), val(v), freq(f) {}
    };

    int capacity;
    int min_freq;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;

public:
    LFUCache(int capacity) : capacity(capacity), min_freq(0) {}

    int get(int key) {
        if (capacity == 0 || !key_table.count(key)) return -1;

        auto node_iter = key_table[key];
        int value = node_iter->val;
        int freq = node_iter->freq;

        // 从原频率链表移除
        freq_table[freq].erase(node_iter);

        // 更新最小频率
        if (freq == min_freq && freq_table[freq].empty()) {
            min_freq++;
        }

        // 插入到新频率链表头部
        freq++;
        freq_table[freq].push_front(Node(key, value, freq));
        key_table[key] = freq_table[freq].begin();

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (key_table.count(key)) {
            // 更新现有节点
            auto node_iter = key_table[key];
            node_iter->val = value;
            get(key); // 更新频率
            return;
        }

        // 需要删除节点
        if (key_table.size() == capacity) {
            auto& min_list = freq_table[min_freq];
            auto node_to_delete = min_list.back();
            key_table.erase(node_to_delete.key);
            min_list.pop_back();
        }

        // 插入新节点
        min_freq = 1;
        freq_table[1].push_front(Node(key, value, 1));
        key_table[key] = freq_table[1].begin();
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
