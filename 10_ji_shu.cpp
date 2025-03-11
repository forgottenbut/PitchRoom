#include "sort_.h"
#include <algorithm>
#include <vector>

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
//  编程实现《基数排序算法》
//  函数参数：乱序整数数组 数组长度
//  函数返回值：返回从小到大排序后的数组
{
    
    if (n == 0) return arr;

    // 找出数组中的最大值
    int max_val = *std::max_element(arr, arr + n);

    // 对每一位进行计数排序
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        std::vector<int> output(n); // 输出数组
        std::vector<int> count(10, 0); // 计数数组

        // 统计每个数字的出现次数
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        // 将计数数组转换为前缀和数组
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // 根据计数数组将元素放入输出数组
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // 将输出数组复制回原数组
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    return arr;
    
}