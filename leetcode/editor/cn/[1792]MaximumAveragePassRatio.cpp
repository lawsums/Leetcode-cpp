// 2025-09-01 08:54:18
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <queue>

using namespace std;

//There is a school that has classes of students and each class will be having 
//a final exam. You are given a 2D integer array classes, where classes[i] = [
//passi, totali]. You know beforehand that in the iᵗʰ class, there are totali total 
//students, but only passi number of students will pass the exam. 
//
// You are also given an integer extraStudents. There are another extraStudents 
//brilliant students that are guaranteed to pass the exam of any class they are 
//assigned to. You want to assign each of the extraStudents students to a class in 
//a way that maximizes the average pass ratio across all the classes. 
//
// The pass ratio of a class is equal to the number of students of the class 
//that will pass the exam divided by the total number of students of the class. The 
//average pass ratio is the sum of pass ratios of all the classes divided by the 
//number of the classes. 
//
// Return the maximum possible average pass ratio after assigning the 
//extraStudents students. Answers within 10⁻⁵ of the actual answer will be accepted. 
//
// 
// Example 1: 
//
// 
//Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
//Output: 0.78333
//Explanation: You can assign the two extra students to the first class. The 
//average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
// 
//
// Example 2: 
//
// 
//Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
//Output: 0.53485
// 
//
// 
// Constraints: 
//
// 
// 1 <= classes.length <= 10⁵ 
// classes[i].length == 2 
// 1 <= passi <= totali <= 10⁵ 
// 1 <= extraStudents <= 10⁵ 
// 
//
// Related Topics 贪心 数组 堆（优先队列） 👍 172 👎 0


// #include "../../../ListOperations.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // 增加的通过率和班级的通过率没有直接关系
        // 定义优先队列：按增加一个学生后的通过率提升量（gain）降序排列（最大堆）
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            double gain_a = (a.first + 1.0) / (a.second + 1.0) - (a.first * 1.0) / a.second;
            double gain_b = (b.first + 1.0) / (b.second + 1.0) - (b.first * 1.0) / b.second;
            return gain_a < gain_b; // 大的在前（最大堆）
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
                pq(cmp);

        for (const auto& elem : classes) {
            pq.push({elem[0], elem[1]});
        }

        for (int i = 0; i < extraStudents; i++) {
            auto tmp = pq.top(); pq.pop();
            tmp.first++; tmp.second++;
            pq.push({tmp});
        }

        double avg_rate = 0;
        while (!pq.empty()) {
            auto tmp = pq.top(); pq.pop();
            avg_rate += tmp.first / (double)tmp.second;
        }
        return avg_rate / classes.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
