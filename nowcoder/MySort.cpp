#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "../DisplayHelper.h"
using namespace display;
using namespace std;

//
class Sort {
public:

    /**
     * 选择排序
     * @param nums 待排序数组
     */
    static void SwitchSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int id = i;
            for (int j = i; j < n; j++) {
                if (nums[j] < nums[id]) id = j;
            }
            swap(nums[id], nums[i]);
        }
    }

    /**
     * 插入排序
     * @param nums 待排序数组
     */
    static void InsertSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1, tmp = nums[j];
            while (j > 0 && tmp < nums[j - 1]) { /* tmp < nums[j - 1]而不是 nums[j] < nums[j - 1] */
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = tmp;
        }
    }

    /**
     * TODO 堆排序
     * @param nums 待排序数组
     */
    static void heapsort() {
        
    }


    /**
     * TODO 快速排序
     * @param nums 待排序数组
     */
    static void quicksort() {

    }

    /**
     * 冒泡排序
     * @param nums 待排序数组
     */
    static void BobbleSort(vector<int>& nums) {
        BobbleSort(nums, 0, nums.size() - 1);
    }

    static void BobbleSort(vector<int>& nums, int start, int end) {
        for (int i = end; i--; i > start) {
            for (int j = start; j <= i; j++) {
                if (nums[j] > nums[j + 1]) swap(nums[j], nums[j + 1]);
            }
        }
    }

    /**
     * 归并排序
     * @param nums 待排序数组
     * @param start 起点[可选]
     * @param end 终点[可选]
     */
    static void MergeSort(vector<int>& nums) {
        MergeSort(nums, 0, nums.size() - 1);
    }

    static void MergeSort(vector<int>& nums, int start, int end) { //
        if (start >= end) return; /* >=是重点 */

        int mid = (start + end) / 2;
        // 需要保证两个子数组是有序的
        MergeSort(nums, start, mid);
        MergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    /**
     * 合并步骤
     * @param nums 待合并数组
     * @param start 合并起点
     * @param mid 合并中点
     * @param end 合并终点
     */
    static void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> tmp;
        int l = start;
        int r = mid + 1;
        while (l <= mid && r <= end) { /* <=而不是< */
            if (nums[l] <= nums[r]) {
                tmp.push_back(nums[l++]);
            } else {
                tmp.push_back(nums[r++]);
            }
        }
        while (l <= mid) tmp.push_back(nums[l++]); /* <= */
        while (r <= end) tmp.push_back(nums[r++]); /* <= */

        for (int i = 0; i < tmp.size(); i++) { /*是tmp的范围而不是nums,nums太大了*/
            nums[start /* 这里要从start开始 */ + i] = tmp[i];
        }
    }

    /**
     * 桶排序
     * @param nums 待排序数组
     */
    static void BucketSort(vector<int>& nums) {
        int minV = accumulate(nums.begin(), nums.end(), INT_MAX, [](int a, int b) { return min(a, b); });
        int maxV = accumulate(nums.begin(), nums.end(), INT_MIN, [](int a, int b) { return max(a, b); });

        int buckets = 3;
        vector<vector<int>> bucketVec(buckets, vector<int>());
        int bucketInterval = (maxV - minV + buckets - 1) / buckets; // 向上取整

        int id = 0;
        for (const auto& num : nums) {
            id = (num - minV) / bucketInterval;
            bucketVec[id].push_back(num);
        }

        for (auto& bucket : bucketVec) {
            BobbleSort(bucket);
        }

        int idx = 0;
        for (const auto& bucket : bucketVec) {
            for (const auto& num : bucket) {
                nums[idx++] = num;
            }
        }
    }

    /**
     * 计数排序
     * @param nums 待排序数组
     */
     static void CountSort(vector<int>& nums) {
         map<int, int> cnts;
         for (const auto& num : nums) {
             cnts[num]++;
         }

         int idx = 0;
         for (const auto& [key, val] : cnts) {
             while (cnts[key]-- > 0) {
                 nums[idx++] = key;
             }
         }
     }

    static void CountSort(vector<double>& nums) {
        map<double, int> cnts;
        for (const auto& num : nums) {
            cnts[num]++;
        }

        int idx = 0;
        for (const auto& [key, val] : cnts) {
            while (cnts[key]-- > 0) {
                nums[idx++] = key;
            }
        }
    }

    /**
     * TODO 基数排序
     * @param nums 待排序数组
     */
     static void RadixSorting(vector<int>& nums) {

     }

};

int main() {
    vector<int> nums = {1, 3, 2, 4, 8, 9, 7, 5, 6, 0, 12, 11};
    print(nums);
//    Sort::BobbleSort(nums);
//    Sort::MergeSort(nums);
//    Sort::BucketSort(nums);
//    Sort::SwitchSort(nums);
//    Sort::InsertSort(nums);

//    vector<double> nums = {1, 3, 2, 3.33, 3.14, -1};
//    Sort::CountSort(nums);

    print(nums);
}
// 64 位输出请用 printf("%lld")
