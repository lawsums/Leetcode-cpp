// 2025-09-04 14:48:12
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <algorithm>

using namespace std;

//Given an integer array nums and an integer k, return the k most frequent 
//elements. You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
// Input: nums = [1,1,1,2,2,3], k = 2 
// 
//
// Output: [1,2] 
//
// Example 2: 
//
// 
// Input: nums = [1], k = 1 
// 
//
// Output: [1] 
//
// Example 3: 
//
// 
// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2 
// 
//
// Output: [1,2] 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// k is in the range [1, the number of unique elements in the array]. 
// It is guaranteed that the answer is unique. 
// 
//
// 
// Follow up: Your algorithm's time complexity must be better than O(n log n), 
//where n is the array's size. 
//
// Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 👍 2064 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
 #include "../../../include/DisplayHelper.h"
using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
 enum class Type {
     MAX,
     MIN
 };

#define MMAX 1
#define MMIN 0

class Solution {
private:

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnts;
        for (int i = 0; i < nums.size(); i++) {
            cnts[nums[i]]++;
        }
        vector<int> keys;
        for (const auto& [key, _] : cnts) {
            keys.push_back(key);
        }

        heapify(keys, cnts, MMAX);

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(heapPop(keys, cnts, MMAX));
        }
        return ans;
    }

    void heapSort1(vector<int>& arr, int type) {
        // 从上往下
        heapify(arr, type);
    }

    void heapSort1(vector<int>& arr, unordered_map<int, int>& mp,int type) {
        // 从上往下
        heapify(arr, mp, type);
    }

    void heapSort2(vector<int>& arr) {

    }

    void heapify(vector<int>& arr, int type) {
        if (type == MMAX) {
            for (int i = 0; i < arr.size(); i++) {
                heapInsert(arr, i);
            }
        } else {
            for (int i = 0; i < arr.size(); i++) {
                heapInsert_min(arr, i);
            }
        }
    }

    void heapify(vector<int>& arr, unordered_map<int, int>& mp, int type) {
        if (type == MMAX) {
            for (int i = 0; i < arr.size(); i++) {
                heapInsert(arr, mp, i);
            }
        } else {
            for (int i = 0; i < arr.size(); i++) {
                heapInsert_min(arr, mp, i);
            }
        }
    }

    static void heapInsert(vector<int>& arr, int i) {
        // 一直往上交换,i = 0时由于((i - 1) / 2)也是0 自动退出
        while (arr[i] > arr[(i - 1) / 2]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    static void heapInsert(vector<int>& arr, unordered_map<int, int>& mp, int i) {
        // 一直往上交换,i = 0时由于((i - 1) / 2)也是0 自动退出
        while (mp[arr[i]] > mp[arr[(i - 1) / 2]]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    static void heapInsert_min(vector<int>& arr, int i) {
        // 一直往上交换,i = 0时由于((i - 1) / 2)也是0 自动退出
        while (arr[i] < arr[(i - 1) / 2]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    static void heapInsert_min(vector<int>& arr, unordered_map<int, int>& mp, int i) {
        // 一直往上交换,i = 0时由于((i - 1) / 2)也是0 自动退出
        while (mp[arr[i]] < mp[arr[(i - 1) / 2]]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int heapPop(vector<int>& arr, int type) {
        int ans = arr.front();
        if (arr.size() == 1) {
            return ans;
        }
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();

        // 下沉
        int n = arr.size();
        int l = 1;
        for (int i = 0; l < n; ) {
            int best;
            if (type == MMAX) {
                best = l + 1 < n && arr[l + 1] > arr[l] ? l + 1 : l;
            } else {
                best = l + 1 < n && arr[l + 1] < arr[l] ? l + 1 : l;
            }
            if (arr[i] >= arr[best]) break;
            else swap(arr[i], arr[best]);
            i = best;
            int l = 2 * i + 1;
        }
        return ans;
    }

    int heapPop(vector<int>& arr, unordered_map<int, int>& mp, int type) {
        int ans = arr.front();
        if (arr.size() == 1) {
            return ans;
        }
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();

        // 下沉
        int n = arr.size();
        int l = 1;
        for (int i = 0; l < n; ) {
            int best;
            if (type == MMAX) {
                best = l + 1 < n && mp[arr[l + 1]] > mp[arr[l]] ? l + 1 : l;
            } else {
                best = l + 1 < n && mp[arr[l + 1]] < mp[arr[l]] ? l + 1 : l;
            }
            if (mp[arr[i]] >= mp[arr[best]]) break;
            else swap(arr[i], arr[best]);
            i = best;
            l = 2 * i + 1;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    auto ans = Solution().topKFrequent(nums, k);
    print(nums);
    print(ans);
}