// 2025-10-30 11:15:59
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


//You have a set which contains all positive integers [1, 2, 3, 4, 5, ...]. 
//
// Implement the SmallestInfiniteSet class: 
//
// 
// SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain 
//all positive integers. 
// int popSmallest() Removes and returns the smallest integer contained in the 
//infinite set. 
// void addBack(int num) Adds a positive integer num back into the infinite set,
// if it is not already in the infinite set. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", 
//"popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
//[[], [2], [], [], [], [1], [], [], []]
//Output
//[null, null, 1, 2, 3, null, 1, 4, 5]
//
//Explanation
//SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
//smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change 
//is made.
//smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest 
//number, and remove it from the set.
//smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
//smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
//smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
//smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the 
//set and
//                                   // is the smallest number, and remove it 
//from the set.
//smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
//smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
// 
//
// 
// Constraints: 
//
// 
// 1 <= num <= 1000 
// At most 1000 calls will be made in total to popSmallest and addBack. 
// 
//
// Related Topics 设计 哈希表 有序集合 堆（优先队列） 👍 97 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_map<int, int> mp;
    int idx = 1;

public:
    SmallestInfiniteSet() {

    }
    
    int popSmallest() {
        int ans = 0;
        if (minHeap.empty()) {
            ans = idx++;
        } else {
            ans = minHeap.top();
            minHeap.pop();
            mp.erase(ans);
        }

        return ans;
    }
    
    void addBack(int num) {
        if (num < idx && !mp.count(num)) { // 一个元素不能重复加入多次
            minHeap.push(num);
            mp[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
//leetcode submit region end(Prohibit modification and deletion)
