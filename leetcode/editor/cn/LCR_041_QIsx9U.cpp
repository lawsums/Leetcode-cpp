// 2025-09-01 18:37:50
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

//English description is not available for the problem. Please switch to 
//Chinese. 
//
// Related Topics 设计 队列 数组 数据流 👍 111 👎 0


// #include "../../../ListOperations.h"
// #include "../../../StringOperations.h"
 #include "../../../include/DisplayHelper.h"
#include <queue>
//using namespace display;
//leetcode submit region begin(Prohibit modification and deletion)

// vector实现
class MovingAverage_vec {
private:
    vector<int> pre;
    vector<int> q;
    int size;
    int l = 0, r = 0;

public:
    /* vector实现 */
    MovingAverage(int size) : size(size) {
//        this->size = size;
        pre.assign(10'001, 0);
        q.assign(10'001, 0);
        cout << this->size << endl;
    }
    
    double next(int val) {
        push(val);
        print_slice(q, l, r);
        cout << "l: " << l << ", r: " << r << endl;
        return (pre[r] - pre[l]) / (double)(r - l);
    }

private:
    void push(int val) {
        cout << "r - l: " << r - l + 1 << ", size: " <<  size << endl;
        if (r - l >= size) l++;     // 维护左边界
        q[r++] = val;
        pre[r] = pre[r - 1] + val;      // 构建pre数组
    }

    int pop() {
        return q[l++];
    }

    template<typename T>
    void print_slice(const std::vector<T>& vec, size_t l, size_t r) {
        // 处理边界
        l = std::min(l, vec.size());
        r = std::min(r, vec.size());

        if (l >= r) {
            std::cout << "[]" << std::endl;
            return;
        }

        std::cout << "[";
        for (size_t i = l; i < r; ++i) {
            std::cout << vec[i];
            if (i < r - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

// 原生数组实现
class MovingAverage_arr {
private:
    int pre[10002] = {0};  // 前缀和数组，多一个位置
    int q[10001] = {0};    // 队列数组
    int size;              // 窗口大小
    int l = 0;             // 左指针
    int r = 0;             // 右指针

public:
    /* 原生数组实现 - 静态数组版本 */
    MovingAverage(int size) : size(size) {
        // 数组已经在声明时初始化
    }

    double next(int val) {
        push(val);
        return (pre[r] - pre[l]) / static_cast<double>(r - l);
    }

private:
    void push(int val) {
        if (r - l >= size) {
            l++;  // 维护左边界
        }

        q[r] = val;
        pre[r + 1] = pre[r] + val;  // 构建pre数组
        r++;
    }

    int pop() {
        if (l < r) {
            return q[l++];
        }
        return 0;
    }
};

#include <queue>
// 队列容器实现
class MovingAverage_q {
private:
    int size, id = 0;              // 窗口大小
    int pre[10002] = {0};  // 前缀和数组，多一个位置
    queue<int> q;

public:
    /* 原生数组实现 - 静态数组版本 */
    MovingAverage(int size) : size(size) {
        // 数组已经在声明时初始化
    }

    double next(int val) {
        if (q.size() >= size) {
            q.pop();
        }
        q.push(val);
        pre[id + 1] = pre[id] + val;
        id++;
        return (pre[id] - pre[id - q.size()]) / (double)q.size();
    }
};

//leetcode submit region end(Prohibit modification and deletion)
