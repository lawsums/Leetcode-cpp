// 2025-09-17 11:41:57
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

//Design a number container system that can do the following: 
//
// 
// Insert or Replace a number at the given index in the system. 
// Return the smallest index for the given number in the system. 
// 
//
// Implement the NumberContainers class: 
//
// 
// NumberContainers() Initializes the number container system. 
// void change(int index, int number) Fills the container at index with the 
//number. If there is already a number at that index, replace it. 
// int find(int number) Returns the smallest index for the given number, or -1 
//if there is no index that is filled by number in the system. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["NumberContainers", "find", "change", "change", "change", "change", "find", 
//"change", "find"]
//[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
//Output
//[null, -1, null, null, null, null, 1, null, 2]
//
//Explanation
//NumberContainers nc = new NumberContainers();
//nc.find(10); // There is no index that is filled with number 10. Therefore, 
//we return -1.
//nc.change(2, 10); // Your container at index 2 will be filled with number 10.
//nc.change(1, 10); // Your container at index 1 will be filled with number 10.
//nc.change(3, 10); // Your container at index 3 will be filled with number 10.
//nc.change(5, 10); // Your container at index 5 will be filled with number 10.
//nc.find(10); // Number 10 is at the indices 1, 2, 3, and 5. Since the 
//smallest index that is filled with 10 is 1, we return 1.
//nc.change(1, 20); // Your container at index 1 will be filled with number 20. 
//Note that index 1 was filled with 10 and then replaced with 20. 
//nc.find(10); // Number 10 is at the indices 2, 3, and 5. The smallest index 
//that is filled with 10 is 2. Therefore, we return 2.
// 
//
// 
// Constraints: 
//
// 
// 1 <= index, number <= 10⁹ 
// At most 10⁵ calls will be made in total to change and find. 
// 
//
// Related Topics 设计 哈希表 有序集合 堆（优先队列） 👍 44 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
#include <set>
#include <unordered_map>
//class NumberContainers {
//private:
//    unordered_map<int, set<int>> mp; // [number: int, indexs: set<int>]
//    unordered_map<int, int> vec; // [index: int, number: int]
//
//public:
//    NumberContainers() {
//
//    }
//
//    void change(int index, int number) {
//        int origin_number;
//        if (!vec.count(index)) { origin_number = -1; }
//        else { origin_number = vec[index]; } // 如果没有出现就置为-1
//
//        vec[index] = number;
//        // 修改mp
//        if (!mp[number].contains(index)) { // 如果不重复
//            mp[number].insert(index);
//            // 如果原本被占据了，需要在mp[origin]中删除原来的index
//            if (origin_number != -1) {
//                if (mp[origin_number].size() == 1) { mp.erase(origin_number); } // 删除整个键
//                else { mp[origin_number].erase(index); }
//            }
//        }
//    }
//
//    int find(int number) {
//        if (!mp.count(number)) return -1;
//        return *mp[number].begin(); // 获取第一个元素
//    }
//};

class NumberContainers {
private:
    unordered_map<int, set<int>> numToIndices; // number -> sorted indices
    unordered_map<int, int> indexToNum;        // index -> current number

public:
    NumberContainers() {}

    void change(int index, int number) {
        // 如果该index已经有数字，需要从原来的数字对应的集合中移除
        if (indexToNum.count(index)) {
            int oldNum = indexToNum[index];
            numToIndices[oldNum].erase(index);

            // 如果该数字对应的索引集合为空，删除整个条目
            if (numToIndices[oldNum].empty()) {
                numToIndices.erase(oldNum);
            }
        }

        // 更新新的映射关系
        indexToNum[index] = number;
        numToIndices[number].insert(index);
    }

    int find(int number) {
        if (!numToIndices.count(number) || numToIndices[number].empty()) {
            return -1;
        }
        return *numToIndices[number].begin();
    }
};
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
//leetcode submit region end(Prohibit modification and deletion)
