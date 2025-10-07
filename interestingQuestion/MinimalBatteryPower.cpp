
#include <DisplayHelper.h>
#include <RandomHelper.h>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using namespace display;

class Solution {
private:

public:
    int solver(vector<pair<int, int>> tasks) {
        // 需求低,消耗高
        // 需求小根堆↑ 消耗大根堆↓
        priority_queue<tuple<int, int>> pq;// 由于默认大根堆，所以需求要以负数加入

        for (auto &task: tasks) {
            auto [cost, need] = task;
            pq.push(make_tuple(-need, cost));
        }

        int ans = 0;
        while (!pq.empty()) {
            auto [neg_need, cost] = pq.top();
            pq.pop();
            ans = max(cost + ans, -neg_need);
        }

        return ans;
    }

    int solver2(vector<pair<int, int>> tasks) {
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return (a.first - a.second) < (b.first - b.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);// 由于默认大根堆，所以需求要以负数加入

        for (auto &task: tasks) {
            pq.push(task);
        }

        int ans = 0;
        while (!pq.empty()) {
            auto [cost, need] = pq.top();
            pq.pop();
            ans = max(cost + ans, need);
        }

        return ans;
    }

    int checker(vector<pair<int, int>> tasks) {
        // 暴力解法，不考虑执行顺序
        vector<bool> used(tasks.size(), false);
        int ans = INT_MAX;

        function<void(int, int)> dfs = [&](int step, int cur) {
            if (step == tasks.size()) ans = min(ans, cur);
            for (int i = 0; i < tasks.size(); i++) {
                if (!used[i]) {
                    used[i] = true;
                    dfs(step + 1, max(cur + tasks[i].first, tasks[i].second));  // tasks[i][0]: 当前消耗, tasks[i][1]: 当前需求
                    used[i] = false;
                }
            }
        };

        dfs(0, 0);
        return ans;
    }
};

int main() {
    auto sol = Solution();
    int N = 100;
    int M = 200;
    int K = 8;
    int wrongs = 0;

    print("测试开始!");
    for (int i = 0; i < N; i++) {
        vector<pair<int, int>> tasks;
        int len = RandomHelper::random_int(3, K);
        for (int j = 0; j < len; j++) {
            int cost = RandomHelper::random_int(1, M / 4);
            int need = RandomHelper::random_int(1, M);
            tasks.push_back(make_pair(cost, need));
        }

        auto ans1 = sol.solver2(tasks);
        auto ans2 = sol.checker(tasks);
        if (i > 0 && i % 10 == 0) {
            print_fmt("测试到{0}轮...", i);
        }
        if (ans1 != ans2) {
             print_fmt("[Wrong]: tasks = {0}, ans1 = {1}, ans2 = {2}", tasks, ans1, ans2);
             wrongs++;
        }
    }

    print_fmt("The precision is {0}%", 100.00 * (1.00 - (1.00 * wrongs / N)));
    print("测试结束!");

}