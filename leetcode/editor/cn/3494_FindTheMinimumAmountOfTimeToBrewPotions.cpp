// 2025-10-09 11:17:02
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//You are given two integer arrays, skill and mana, of length n and m, 
//respectively. 
//
// In a laboratory, n wizards must brew m potions in order. Each potion has a 
//mana capacity mana[j] and must pass through all the wizards sequentially to be 
//brewed properly. The time taken by the iᵗʰ wizard on the jᵗʰ potion is timeij = 
//skill[i] * mana[j]. 
//
// Since the brewing process is delicate, a potion must be passed to the next 
//wizard immediately after the current wizard completes their work. This means the 
//timing must be synchronized so that each wizard begins working on a potion 
//exactly when it arrives. 
//
// Return the minimum amount of time required for the potions to be brewed 
//properly. 
//
// 
// Example 1: 
//
// 
// Input: skill = [1,5,2,4], mana = [5,1,4,2] 
// 
//
// Output: 110 
//
// Explanation: 
//
// 
// 
// 
// Potion Number 
// Start time 
// Wizard 0 done by 
// Wizard 1 done by 
// Wizard 2 done by 
// Wizard 3 done by 
// 
// 
// 0 
// 0 
// 5 
// 30 
// 40 
// 60 
// 
// 
// 1 
// 52 
// 53 
// 58 
// 60 
// 64 
// 
// 
// 2 
// 54 
// 58 
// 78 
// 86 
// 102 
// 
// 
// 3 
// 86 
// 88 
// 98 
// 102 
// 110 
// 
// 
// 
//
// As an example for why wizard 0 cannot start working on the 1ˢᵗ potion before 
//time t = 52, consider the case where the wizards started preparing the 1ˢᵗ 
//potion at time t = 50. At time t = 58, wizard 2 is done with the 1ˢᵗ potion, but 
//wizard 3 will still be working on the 0ᵗʰ potion till time t = 60. 
//
// Example 2: 
//
// 
// Input: skill = [1,1,1], mana = [1,1,1] 
// 
//
// Output: 5 
//
// Explanation: 
//
// 
// Preparation of the 0ᵗʰ potion begins at time t = 0, and is completed by time 
//t = 3. 
// Preparation of the 1ˢᵗ potion begins at time t = 1, and is completed by time 
//t = 4. 
// Preparation of the 2ⁿᵈ potion begins at time t = 2, and is completed by time 
//t = 5. 
// 
//
// Example 3: 
//
// 
// Input: skill = [1,2,3,4], mana = [1,2] 
// 
//
// Output: 21 
//
// 
// Constraints: 
//
// 
// n == skill.length 
// m == mana.length 
// 1 <= n, m <= 5000 
// 1 <= mana[i], skill[i] <= 5000 
// 
//
// Related Topics 数组 前缀和 模拟 👍 26 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        deque<tuple<int, long long, long long>> dq;
        int idx = 0;
        long long cur = 0;

        vector<int> suf(skill.size());
        transform(skill.begin(), skill.end(), suf.begin(),
                       [&](int x) { return x * mana[idx]; });
        partial_sum(suf.rbegin(), suf.rend(), suf.rbegin()); // 后缀和

        for (int i = 0; i < skill.size(); i++) {
            dq.push_back(make_tuple(
                    i,
                    cur,
                    cur + suf[i]
                    ));
            cur += mana[idx] * skill[i];
        }
        idx++;
        transform(skill.begin(), skill.end(), suf.begin(),
                  [&](int x) { return x * mana[idx]; });
        partial_sum(suf.rbegin(), suf.rend(), suf.rbegin()); // 后缀和

        long long ans = 0;
        while (idx < mana.size()) {
//            print_fmt("dq: {0}", dq);

            vector<long long> real_startt(skill.size(), 0);
//            vector<long long> ends(skill.size(), 0);
            long long max_end = 0;
            int max_id = 0;
            for (int i = 0; i < skill.size(); i++) {
                auto [id, startt, endall] = dq.front();
                dq.pop_front();
                // 求一个最大的endall, 其他的任务的startt变为 max_end - suf[i]
                if (endall >= max_end) {
                    if (endall > max_end) max_end = endall;
                    max_id = i;
                }
//                ends[i] = endall;
            }

            ans = max(ans, max_end);

            for (int i = 0; i < skill.size(); i++) {
                real_startt[i] = max_end - suf[i] + suf[max_id]; // 修正时间
            }

            if (idx == mana.size()) break;

            idx++; // 构造新的前缀和
            transform(skill.begin(), skill.end(), suf.begin(),
                      [&](int x) { return x * mana[idx]; });
            partial_sum(suf.rbegin(), suf.rend(), suf.rbegin()); // 后缀和
            for (int i = 0; i < skill.size(); i++) {
                dq.push_back(make_tuple(
                        i,
                        real_startt[i],
                        real_startt[i] + suf[i]));
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> skill = {1,5,2,4};
    vector<int> mana = {5,1,4,2};
    cout << Solution().minTime(skill, mana) << endl;
}