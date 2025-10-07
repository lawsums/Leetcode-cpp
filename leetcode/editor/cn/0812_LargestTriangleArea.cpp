// 2025-09-27 00:08:17
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//Given an array of points on the X-Y plane points where points[i] = [xi, yi], 
//return the area of the largest triangle that can be formed by any three 
//different points. Answers within 10⁻⁵ of the actual answer will be accepted. 
//
// 
// Example 1: 
// 
// 
//Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
//Output: 2.00000
//Explanation: The five points are shown in the above figure. The red triangle 
//is the largest.
// 
//
// Example 2: 
//
// 
//Input: points = [[1,0],[0,0],[0,1]]
//Output: 0.50000
// 
//
// 
// Constraints: 
//
// 
// 3 <= points.length <= 50 
// -50 <= xi, yi <= 50 
// All the given points are unique. 
// 
//
// Related Topics 几何 数组 数学 👍 209 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double line(pair<int, int> p1, pair<int, int> p2) {
        auto [x1, y1] = p1;
        auto [x2, y2] = p2;
        return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    }

    double area(double a, double b, double c) {
        double h = (a + b + c) / 2;
        return sqrt(h * (h - a) * (h - b) * (h - c));
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;

        for (int i = 0; i < points.size() - 2; i++) {
            for (int j = i + 1; j < points.size() - 1; j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    auto a = line(make_pair(points[i][0], points[i][1]), make_pair(points[j][0], points[j][1]));
                    auto b = line(make_pair(points[j][0], points[j][1]), make_pair(points[k][0], points[k][1]));
                    auto c = line(make_pair(points[i][0], points[i][1]), make_pair(points[k][0], points[k][1]));
                    auto s = area(a, b, c);
                    ans = max(ans, s);
                }
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
