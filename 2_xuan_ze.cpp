
#include "sort_.h"

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
{

    int print_count = 0; // 用于记录已经打印的选择操作次数
    int min_index; // 用于记录每轮选择的最小值索引

    for (int i = 0; i < n - 1; i++) { // 外层循环控制选择次数
        min_index = i; // 假设当前索引为最小值索引
        for (int j = i + 1; j < n; j++) { // 内层循环寻找最小值
            if (arr[j] < arr[min_index]) {
                min_index = j; // 更新最小值索引
            }
        }
        // 交换当前索引和最小值索引的元素
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
        print_count++; // 每完成一次选择操作，打印次数加1
        if (print_count <= 3) { // 如果是前三次选择操作，打印当前数组状态
            print_array(arr, n);
        }
    }
    print_array(arr, n); // 最终打印升序序列
    
}


