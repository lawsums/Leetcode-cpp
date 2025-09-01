#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <unordered_map>
#include <random> // 包含 random

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> mp;           // index -> value
    unordered_map<int, int> index_of_val; // value -> index (你原来用的是bool，应该是int存储索引)
    int size;                             // 当前元素个数，比 index 更清晰
    mt19937 gen;                          // **关键修改**：将引擎作为成员变量

public:
    /** Initialize your data structure here. */
    RandomizedSet() : size(0), gen(random_device{}()) {
        // 使用初始化列表
        // gen(random_device{}()) 会创建一个临时的 random_device 对象，并用其生成的种子初始化 gen
        // 也可以分开写：
        // random_device rd;
        // gen = mt19937(rd());
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (index_of_val.find(val) != index_of_val.end()) { // **关键修改**：检查是否存在
            return false;
        } else {
            mp[size] = val;                 // 将新元素放在末尾 (索引为 size)
            index_of_val[val] = size;       // 记录值到索引的映射
            size++;                         // 元素个数加一
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (index_of_val.find(val) == index_of_val.end()) { // **关键修改**：检查是否存在
            return false;
        } else {
            int index_to_remove = index_of_val[val]; // 要删除的元素的索引
            int last_element = mp[size - 1];         // 最后一个元素的值

            // 将最后一个元素移动到要删除的位置
            mp[index_to_remove] = last_element;
            // 更新最后一个元素的新索引
            index_of_val[last_element] = index_to_remove;

            // 从映射中删除旧的条目
            index_of_val.erase(val);
            // 移除数组末尾的旧位置 (逻辑上，我们通过减小 size 来实现)
            size--;

            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        // 创建一个分布器，生成 [0, size-1] 范围内的整数
        uniform_int_distribution<int> dis(0, size - 1);
        int random_index = dis(gen); // 使用成员变量 gen
        return mp[random_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// 测试
//int main() {
//    RandomizedSet randomizedSet;
//    cout << randomizedSet.insert(1) << endl; // true
//    cout << randomizedSet.remove(2) << endl; // false
//    cout << randomizedSet.insert(2) << endl; // true
//    cout << randomizedSet.getRandom() << endl; // 1 or 2
//    cout << randomizedSet.remove(1) << endl; // true
//    cout << randomizedSet.insert(2) << endl; // false
//    cout << randomizedSet.getRandom() << endl; // 2
//    return 0;
//}