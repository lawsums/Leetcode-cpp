#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MySequence {
  private:
    int logicalSize = 0; // 逻辑大小
    // int allocatedSize = 0; // 内存占用大小
    int* elems = new int[100'001];

  public:
    void push_back(int val) { // push_back = 1, val = stoi(x)
        elems[logicalSize++] = val;
    }

    int pop_back() { // pop_back = 2
        return elems[--logicalSize];
    }

    int at(int index) { // at = 3, index = stoi(i)
        cout << elems[index] << endl;
        return elems[index];
    }

    void insert(int index, int val) { // insert = 4, index = stoi(i), val = stoi(x)
        for (int i = logicalSize; i > index + 1; i--) {
            elems[i] = elems[i - 1];
        }
        elems[index + 1] = val;
        logicalSize++;
    }

    void sort() {
        heapSort(elems, logicalSize, true);
    }

    void sort_reverse() {
        heapSort(elems, logicalSize, false);
    }

// 统一的下沉操作
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
                return;
            } else {
                // 交换父节点和子节点
                swap(arr[parent], arr[child]);
                parent = child;
                child = 2 * parent + 1;
            }
        }
    }

// 统一的堆排序
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

    // // 通用下沉操作
    // template<typename T, typename Compare>
    // void siftDown(vector<T>& arr, int start, int end, Compare comp) {
    //     int parent = start;
    //     int child = 2 * parent + 1; // 左子节点

    //     while (child <= end) {
    //         // 选择符合比较条件的子节点
    //         if (child + 1 <= end && comp(arr[child], arr[child + 1])) {
    //             child++;
    //         }

    //         // 如果当前堆结构已满足比较条件
    //         if (comp(arr[child], arr[parent])) {
    //             return;
    //         } else {
    //             // 交换父节点和子节点
    //             swap(arr[parent], arr[child]);
    //             parent = child;
    //             child = 2 * parent + 1;
    //         }
    //     }
    // }

    // // 通用堆排序
    // template<typename T, typename Compare>
    // void heapSort(vector<T>& arr, Compare comp = less<T>()) {
    //     int n = arr.size();
    //     if (n <= 1) return;

    //     // 构建堆：从最后一个非叶子节点开始
    //     for (int i = n / 2 - 1; i >= 0; i--) {
    //         siftDown(arr, i, n - 1, comp);
    //     }

    //     // 排序：依次将堆顶元素放到末尾并调整堆
    //     for (int i = n - 1; i > 0; i--) {
    //         swap(arr[0], arr[i]);
    //         siftDown(arr, 0, i - 1, comp);
    //     }
    // }

    int size() { // size = 7
        cout << logicalSize << endl;
        return logicalSize;
    }

    void output() {  // output = 8
        for (int i = 0; i < logicalSize; i++) {
            if (i != logicalSize) cout << elems[i] << " ";
            else cout << elems[i];
        }
        cout << endl;
    }
};

int main() {
    MySequence sq = MySequence();

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        string tmp;
        vector<int> query;
        while (ss >> tmp) {
            query.push_back(stoi(tmp));
        }

        if (query[0] == 1) {
            sq.push_back(query[1]);
        } else if (query[0] == 2) {
            sq.pop_back();
        } else if (query[0] == 3) {
            sq.at(query[1]);
        } else if (query[0] == 4) {
            sq.insert(query[1], query[2]);
        } else if (query[0] == 5) {
            sq.sort();
        } else if (query[0] == 6) {
            sq.sort_reverse();
        } else if (query[0] == 7) {
            sq.size();
        } else if (query[0] == 8) {
            sq.output();
        }
    }
}
// 64 位输出请用 printf("%lld")
