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

void sort_array(int *arr, int n)
//  编程实现《计数排序算法》
//  函数参数：乱序整数数组 数组长度
//  要求输出：调用print_array(int *arr, int n)输出：
//  每一行一个元素及其个数（升序），如 1 1
//  以及最终的升序序列
{
    // 请在这里补充代码，完成本关任务
   
    if (n == 0) return;

    // 找出数组中的最大值和最小值
    int max_val = *std::max_element(arr, arr + n);
    int min_val = *std::min_element(arr, arr + n);

    // 计算计数数组的大小
    int range = max_val - min_val + 1;

    // 初始化计数数组
    std::vector<int> count(range, 0);

    // 统计每个元素的出现次数
    for (int i = 0; i < n; i++) {
        count[arr[i] - min_val]++;
    }

    // 输出每个元素及其个数
    for (int i = 0; i < range; i++) {
        if (count[i] > 0) {
            printf("%d %d\n", i + min_val, count[i]);
        }
    }

    // 根据计数数组重构原数组
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + min_val;
            count[i]--;
        }
    }

    // 输出最终的升序序列
    print_array(arr, n);
    
}