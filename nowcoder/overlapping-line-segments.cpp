#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// overlapping-line-segments
// [线段重合_牛客题霸_牛客网](https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37)
int main() {
    int N;
    cin >> N; // 读取N的大小

    int a, b;
    vector<pair<int, int>> intervals;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        intervals.push_back({a, b});
    } // 读取数据完毕

    // 使用最小堆来存储结束时间
    priority_queue<int, vector<int>, greater<int>> pq;

    // 按开始时间排序
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    int ans = 0;
    for (int i = 0; i < N; i++) {
        // 移除所有已经结束的会议
        while (!pq.empty() && pq.top() <= intervals[i].first) {
            pq.pop();
        }
        // 添加当前会议的结束时间
        pq.push(intervals[i].second);
        // 更新最大同时进行的会议数量
        ans = max(ans, (int)pq.size());
    }

    cout << ans << endl;
    return 0;
}
