#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MySequence {
private:
    int logicalSize = 0; // 逻辑大小（当前元素数量）
    int* elems = new int[100'001]; // 分配固定大小的数组，最大容量100001

public:
    /**
     * 在序列末尾添加元素
     * @param val 要添加的元素值
     */
    void push_back(int val) {
        elems[logicalSize++] = val;
    }

    /**
     * 删除并返回序列末尾的元素
     * @return 被删除的元素值
     */
    int pop_back() {
        return elems[--logicalSize];
    }

    /**
     * 访问指定索引位置的元素并输出
     * @param index 要访问的索引位置
     * @return 指定位置的元素值
     */
    int at(int index) {
        cout << elems[index] << endl;
        return elems[index];
    }

    /**
     * 在指定索引位置后插入元素
     * @param index 插入位置的索引（插入在index+1位置）
     * @param val 要插入的元素值
     */
    void insert(int index, int val) {
        // 将index+1位置后的元素向后移动一位
        for (int i = logicalSize; i > index + 1; i--) {
            elems[i] = elems[i - 1];
        }
        elems[index + 1] = val; // 在index+1位置插入新元素
        logicalSize++; // 逻辑大小增加
    }

    /**
     * 对序列进行升序排序（使用堆排序算法）
     */
    void sort() {
        heapSort(elems, logicalSize, true);
    }

    /**
     * 对序列进行降序排序（使用堆排序算法）
     */
    void sort_reverse() {
        heapSort(elems, logicalSize, false);
    }

    /**
     * 堆排序的下沉操作
     * @param arr 待排序数组
     * @param start 下沉起始位置
     * @param end 下沉结束位置
     * @param ascending 排序方向：true为升序，false为降序
     */
    void siftDown(int arr[], int start, int end, bool ascending) {
        int parent = start;
        int child = 2 * parent + 1; // 左子节点

        while (child <= end) {
            // 根据排序方向选择子节点
            if (child + 1 <= end) {
                if (ascending && arr[child] < arr[child + 1]) {
                    child++; // 升序：选择较大的子节点
                } else if (!ascending && arr[child] > arr[child + 1]) {
                    child++; // 降序：选择较小的子节点
                }
            }

            // 根据排序方向检查堆结构是否满足
            bool heapSatisfied = ascending ? (arr[parent] >= arr[child]) :
                                           (arr[parent] <= arr[child]);

            if (heapSatisfied) {
                return; // 堆结构已满足，停止下沉
            } else {
                // 交换父节点和子节点，继续下沉
                swap(arr[parent], arr[child]);
                parent = child;
                child = 2 * parent + 1;
            }
        }
    }

    /**
     * 堆排序算法实现
     * @param arr 待排序数组
     * @param n 数组元素数量
     * @param ascending 排序方向：true为升序，false为降序
     */
    void heapSort(int arr[], int n, bool ascending = true) {
        // 构建堆：从最后一个非叶子节点开始，向前进行下沉操作
        for (int i = n / 2 - 1; i >= 0; i--) {
            siftDown(arr, i, n - 1, ascending);
        }

        // 依次将堆顶元素与末尾元素交换，并重新调整堆
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            siftDown(arr, 0, i - 1, ascending);
        }
    }

    /**
     * 获取序列当前大小并输出
     * @return 序列的逻辑大小
     */
    int size() {
        cout << logicalSize << endl;
        return logicalSize;
    }

    /**
     * 输出序列中的所有元素（空格分隔）
     */
    void output() {
        for (int i = 0; i < logicalSize; i++) {
            if (i != logicalSize - 1)
                cout << elems[i] << " "; // 非最后一个元素，输出元素加空格
            else
                cout << elems[i]; // 最后一个元素，只输出元素
        }
        cout << endl;
    }
};

int main() {
    MySequence sq = MySequence(); // 创建序列对象

    int n; // 操作数量
    cin >> n;
    cin.ignore(); // 忽略换行符

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line); // 读取整行输入
        stringstream ss(line); // 使用字符串流解析输入

        string tmp;
        vector<int> query; // 存储解析后的操作参数
        while (ss >> tmp) {
            query.push_back(stoi(tmp)); // 将字符串转换为整数
        }

        // 使用switch语句处理不同操作
        switch (query[0]) {
            case 1: // push_back操作
                sq.push_back(query[1]);
                break;
            case 2: // pop_back操作
                sq.pop_back();
                break;
            case 3: // at操作（访问指定位置元素）
                sq.at(query[1]);
                break;
            case 4: // insert操作（在指定位置后插入元素）
                sq.insert(query[1], query[2]);
                break;
            case 5: // sort操作（升序排序）
                sq.sort();
                break;
            case 6: // sort_reverse操作（降序排序）
                sq.sort_reverse();
                break;
            case 7: // size操作（获取序列大小）
                sq.size();
                break;
            case 8: // output操作（输出序列内容）
                sq.output();
                break;
            default: // 无效操作码处理
                cout << "Invalid operation code: " << query[0] << endl;
                break;
        }
    }

    return 0; // 程序正常结束
}
