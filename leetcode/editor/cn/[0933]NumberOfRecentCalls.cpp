// 2025-09-04 17:34:43
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//You have a RecentCounter class which counts the number of recent requests 
//within a certain time frame. 
//
// Implement the RecentCounter class: 
//
// 
// RecentCounter() Initializes the counter with zero recent requests. 
// int ping(int t) Adds a new request at time t, where t represents some time 
//in milliseconds, and returns the number of requests that has happened in the past 
//3000 milliseconds (including the new request). Specifically, return the number 
//of requests that have happened in the inclusive range [t - 3000, t]. 
// 
//
// It is guaranteed that every call to ping uses a strictly larger value of t 
//than the previous call. 
//
// 
// Example 1: 
//
// 
//Input
//["RecentCounter", "ping", "ping", "ping", "ping"]
//[[], [1], [100], [3001], [3002]]
//Output
//[null, 1, 2, 3, 3]
//
//Explanation
//RecentCounter recentCounter = new RecentCounter();
//recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
//recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], 
//return 2
//recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], 
//return 3
//recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,300
//2], return 3
// 
//
// 
// Constraints: 
//
// 
// 1 <= t <= 10⁹ 
// Each test case will call ping with strictly increasing values of t. 
// At most 10⁴ calls will be made to ping. 
// 
//
// Related Topics 设计 队列 数据流 👍 276 👎 0


// #include "../../../ListOperations.h"
// #include "../../../TreeOperations.h"
// #include "../../../StringOperations.h"
// #include "../../../DisplayHelper.h"
// using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)
class RecentCounter {
private:
    int* RecentPings;
    int l = 0, r = 0;

public:
    RecentCounter() {
        RecentPings = new int[10'001];
    }

    ~RecentCounter() {
        delete[] RecentPings;
    }

    int ping(int t) {
        RecentPings[r++] = t;
        while (RecentPings[r - 1] > RecentPings[l] + 3000) {l++;}
        return r - l;
    }
};


/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
//leetcode submit region end(Prohibit modification and deletion)
