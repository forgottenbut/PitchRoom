#include "sort_.h"
#include <vector>
#include <algorithm>

void print_array(int *arr, int n)
// 打印数组
{
    if(n==0){
        printf("ERROR: Array length is ZERO\n");
        return;
    }
    printf("%d", arr[0]);
    for (int i=1; i<n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int* sort_array(int *arr, int n)
//  编程实现《桶排序算法》
//  函数参数：乱序整数数组 数组长度
//  函数返回值：返回从小到大排序后的数组
{
    
    if (n == 0) return arr;

    // 找出数组中的最大值和最小值
    int max_val = *std::max_element(arr, arr + n);
    int min_val = *std::min_element(arr, arr + n);

    // 计算桶的数量
    int bucket_count = (max_val - min_val) / n + 1;
    std::vector<std::vector<int>> buckets(bucket_count);

    // 将元素分配到各个桶中
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_val) / n;
        buckets[bucket_index].push_back(arr[i]);
    }

    // 对每个桶中的元素进行排序
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    // 将各个桶中的元素合并到原数组中
    int index = 0;
    for (const auto& bucket : buckets) {
        for (int num : bucket) {
            arr[index++] = num;
        }
    }

    return arr;
    
}