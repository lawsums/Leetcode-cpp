// 2025/9/26
#include <DisplayHelper.h>
#include <bits/stdc++.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
 #include <RandomHelper.h>
 #include <ComparatorHelper.h>

using namespace std;
using namespace display;

class Solution {
private:

public:
    bool solver(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (const auto& num : nums) {
            mp[num]++;
        }

        int max_cnt = 1;
        for (const auto& [_, v] : mp) {
            max_cnt = max(max_cnt, v);
        }

        return nums.size() / max_cnt >= k;
    }

    bool checker(vector<int>& nums, int k) {
        int buckets_num = nums.size() / k; // 分成这么多个桶

        ranges::sort(nums);
        vector<vector<int>> buckets(buckets_num, vector<int>{});
        for (int i = 0; i < nums.size(); i++) {
            int id = 0;
            if (buckets.back().size() >= k) return true;
            while (id < buckets_num && ((i > 0 && nums[i] == nums[i - 1]) || (buckets[id].size() >= k))) {
                id++;
            }
            if (id >= buckets_num) return false;
            buckets[id].push_back(nums[i]);
        }

        return true; // 保证不出错
    }
};

int main() {
    Solution sol;

    cout << "=== 分桶算法测试 ===" << endl;

    // 直接使用 UniversalComparator 构造函数，避免工厂方法
    auto param_gen = [](int test_id) {
        int size = RandomHelper::random_int(6, 30);
        vector<int> nums = RandomHelper::random_array(size, 1, 5);
        int k = max(2, RandomHelper::random_int(2, size/2));
        ranges::sort(nums);
        return make_tuple(nums, k);
    };

    UniversalComparator<bool, vector<int>, int> comparator(
            [&](vector<int> nums, int k) { return sol.solver(nums, k); },
            [&](vector<int> nums, int k) { return sol.checker(nums, k); },
            param_gen,
            "Solver", "Checker"
    );

    comparator.batch_test(20, 5);
    return 0;
}
