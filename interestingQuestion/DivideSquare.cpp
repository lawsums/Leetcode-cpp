// 2025/9/28
#include <DisplayHelper.h>
#include <bits/stdc++.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        // 计算两个正方形的中心点
        double center1_x = square1[0] + square1[2] / 2.0;
        double center1_y = square1[1] + square1[2] / 2.0;

        double center2_x = square2[0] + square2[2] / 2.0;
        double center2_y = square2[1] + square2[2] / 2.0;

        // 处理垂直线情况 (斜率无穷大)
        if (center1_x == center2_x) {
            double min_y = min(square1[1], square2[1]);
            double max_y = max(square1[1] + square1[2], square2[1] + square2[2]);
            return {center1_x, min_y, center1_x, max_y};
        }

        // 计算斜率
        double k = (center2_y - center1_y) / (center2_x - center1_x);
        double b = center1_y - k * center1_x;

        // 收集所有可能的交点
        vector<pair<double, double>> points;

        // 正方形1的边界交点
        addIntersections(square1, k, b, points);
        // 正方形2的边界交点
        addIntersections(square2, k, b, points);

        double max_dist = -1;
        pair<double, double> p1, p2;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                double dist = pow(points[i].first - points[j].first, 2) +
                              pow(points[i].second - points[j].second, 2);
                if (dist > max_dist) {
                    max_dist = dist;
                    p1 = points[i];
                    p2 = points[j];
                }
            }
        }

        // 按要求排序：如果x1 != x2，保证x1 < x2；否则保证y1 <= y2
        if (p1.first != p2.first) {
            if (p1.first > p2.first) {
                swap(p1, p2);
            }
        } else {
            if (p1.second > p2.second) {
                swap(p1, p2);
            }
        }

        return {p1.first, p1.second, p2.first, p2.second};
    }

private:
    void addIntersections(vector<int>& square, double k, double b, vector<pair<double, double>>& points) {
        double x_min = square[0];
        double x_max = square[0] + square[2];
        double y_min = square[1];
        double y_max = square[1] + square[2];

        // 与左右边界的交点
        vector<double> xs = {x_min, x_max};
        for (double x : xs) {
            double y = k * x + b;
            if (y >= y_min && y <= y_max) {
                points.push_back({x, y});
            }
        }

        // 与上下边界的交点
        vector<double> ys = {y_min, y_max};
        for (double y : ys) {
            double x = (y - b) / k;
            if (x >= x_min && x <= x_max) {
                points.push_back({x, y});
            }
        }
    }
};



int main() {

}