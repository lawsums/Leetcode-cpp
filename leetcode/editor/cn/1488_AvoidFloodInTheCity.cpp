// 2025-10-07 10:31:47
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//Your country has an infinite number of lakes. Initially, all the lakes are 
//empty, but when it rains over the nth lake, the nth lake becomes full of water. If 
//it rains over a lake that is full of water, there will be a flood. Your goal is 
//to avoid floods in any lake. 
//
// Given an integer array rains where: 
//
// 
// rains[i] > 0 means there will be rains over the rains[i] lake. 
// rains[i] == 0 means there are no rains this day and you can choose one lake 
//this day and dry it. 
// 
//
// Return an array ans where: 
//
// 
// ans.length == rains.length 
// ans[i] == -1 if rains[i] > 0. 
// ans[i] is the lake you choose to dry in the ith day if rains[i] == 0. 
// 
//
// If there are multiple valid answers return any of them. If it is impossible 
//to avoid flood return an empty array. 
//
// Notice that if you chose to dry a full lake, it becomes empty, but if you 
//chose to dry an empty lake, nothing changes. 
//
// 
// Example 1: 
//
// 
//Input: rains = [1,2,3,4]
//Output: [-1,-1,-1,-1]
//Explanation: After the first day full lakes are [1]
//After the second day full lakes are [1,2]
//After the third day full lakes are [1,2,3]
//After the fourth day full lakes are [1,2,3,4]
//There's no day to dry any lake and there is no flood in any lake.
// 
//
// Example 2: 
//
// 
//Input: rains = [1,2,0,0,2,1]
//Output: [-1,-1,2,1,-1,-1]
//Explanation: After the first day full lakes are [1]
//After the second day full lakes are [1,2]
//After the third day, we dry lake 2. Full lakes are [1]
//After the fourth day, we dry lake 1. There is no full lakes.
//After the fifth day, full lakes are [2].
//After the sixth day, full lakes are [1,2].
//It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another 
//acceptable scenario.
// 
//
// Example 3: 
//
// 
//Input: rains = [1,2,0,1,2]
//Output: []
//Explanation: After the second day, full lakes are  [1,2]. We have to dry one 
//lake in the third day.
//After that, it will rain over lakes [1,2]. It's easy to prove that no matter 
//which lake you choose to dry in the 3rd day, the other one will flood.
// 
//
// 
// Constraints: 
//
// 
// 1 <= rains.length <= 10⁵ 
// 0 <= rains[i] <= 10⁹ 
// 
//
// Related Topics 贪心 数组 哈希表 二分查找 堆（优先队列） 👍 248 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        auto ans = vector<int>(n, -1);
        auto next = vector<int>(n, -1); // 构建数组
        unordered_map<int, int> last_pos;
        unordered_map<int, int> full;

        auto pq = priority_queue<tuple<int, int>>(); // 将元素以负数形式加入

        for (int i = n - 1; i >= 0; i--) {
            if (last_pos.count(rains[i])) {
                next[i] = last_pos[rains[i]];
            }

            last_pos[rains[i]] = i;
        }


        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                if (next[i] != -1) { // 如果有后续位置的话加入优先队列
                    pq.push({-next[i], rains[i]}); // 因为是小根堆所以加入负数
                }
                if (full[rains[i]] == 1) {
                    return {};
                }
                full[rains[i]] = 1;
            } else {
                if (!pq.empty()) {
                    auto [key, val] = pq.top();
                    ans[i] = val;
                    full[val] = 0;
                    pq.pop();
                } else {
                    if (full[1] == 1) {
                        full[1] = 0;
                    }
                    ans[i] = 1;
                }
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
     vector<int> rains = {1,2,0,1,2};
     Solution().avoidFlood(rains);
}