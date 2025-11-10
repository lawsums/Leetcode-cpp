// 2025-11-02 17:18:01
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


//You are given n tasks labeled from 0 to n - 1 represented by a 2D integer 
//array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the ith 
//task will be available to process at enqueueTimei and will take processingTimei to 
//finish processing. 
//
// You have a single-threaded CPU that can process at most one task at a time 
//and will act in the following way: 
//
// 
// If the CPU is idle and there are no available tasks to process, the CPU 
//remains idle. 
// If the CPU is idle and there are available tasks, the CPU will choose the 
//one with the shortest processing time. If multiple tasks have the same shortest 
//processing time, it will choose the task with the smallest index. 
// Once a task is started, the CPU will process the entire task without 
//stopping. 
// The CPU can finish a task then start a new one instantly. 
// 
//
// Return the order in which the CPU will process the tasks. 
//
// 
// Example 1: 
//
// 
//Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
//Output: [0,2,3,1]
//Explanation: The events go as follows: 
//- At time = 1, task 0 is available to process. Available tasks = {0}.
//- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {
//}.
//- At time = 2, task 1 is available to process. Available tasks = {1}.
//- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
//- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as 
//it is the shortest. Available tasks = {1}.
//- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
//- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is 
//the shortest. Available tasks = {1}.
//- At time = 6, the CPU finishes task 3 and starts processing task 1. 
//Available tasks = {}.
//- At time = 10, the CPU finishes task 1 and becomes idle.
// 
//
// Example 2: 
//
// 
//Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
//Output: [4,3,2,0,1]
//Explanation: The events go as follows:
//- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
//- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {
//0,1,2,3}.
//- At time = 9, the CPU finishes task 4 and starts processing task 3. 
//Available tasks = {0,1,2}.
//- At time = 13, the CPU finishes task 3 and starts processing task 2. 
//Available tasks = {0,1}.
//- At time = 18, the CPU finishes task 2 and starts processing task 0. 
//Available tasks = {1}.
//- At time = 28, the CPU finishes task 0 and starts processing task 1. 
//Available tasks = {}.
//- At time = 40, the CPU finishes task 1 and becomes idle.
// 
//
// 
// Constraints: 
//
// 
// tasks.length == n 
// 1 <= n <= 10⁵ 
// 1 <= enqueueTimei, processingTimei <= 10⁹ 
// 
//
// Related Topics 数组 排序 堆（优先队列） 👍 132 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // 放一个未解锁堆，一个解锁堆
        auto cmp1 = [=](int a, int b) {
            return tasks[a][0] > tasks[b][0]; // 按照解锁时间进行排序
        };
        auto cmp2 = [=](int a, int b) {
            return tasks[a][1] == tasks[b][1] ? a > b : tasks[a][1] > tasks[b][1]; // 按照执行时长进行排序
        };

        priority_queue<int, vector<int>, decltype(cmp1)> unlock(cmp1);
        priority_queue<int, vector<int>, decltype(cmp2)> lock(cmp2);

        for (size_t i = 0; i < tasks.size(); i++) {
            unlock.push(i);
        } // 从现在开始加入时间

        int ts = 0;
        int k = tasks.size();
        vector<int> ans;
        while (k--) { // 每次执行一个任务
            if (lock.empty()) { // 如果当前没有任务的话可以直接跳过中间时间
                ts = max(ts, tasks[unlock.top()][0]);
            }
            while (!unlock.empty() && tasks[unlock.top()][0] <= ts) {
                lock.push(unlock.top()); unlock.pop();
            } // 将所有离当前最近的相同解锁时间的任务加入lock堆中

            // 挑选一个任务进行执行
            auto id = lock.top();
            ts += tasks[id][1];
            ans.push_back(id); lock.pop();
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<vector<int>> tasks = {{1,2},{2,4},{3,2},{4,1}};
    auto ans = Solution().getOrder(tasks);
    print_fmt("ans = {0}", ans);
}