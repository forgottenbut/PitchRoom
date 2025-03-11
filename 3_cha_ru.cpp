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
    int print_count = 0; // 用于记录已经打印的插入操作次数

    for (int i = 1; i < n; i++) { // 外层循环控制插入次数
        int key = arr[i]; // 当前要插入的元素
        int j = i - 1; // 已排序部分的最后一个元素索引

        // 在已排序部分找到插入位置
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // 向右移动元素
            j--;
        }
        arr[j + 1] = key; // 插入当前元素

        print_count++; // 每完成一次插入操作，打印次数加1
        if (print_count <= 3) { // 如果是前三次插入操作，打印当前数组状态
            print_array(arr, n);
        }
    }
    print_array(arr, n); // 最终打印升序序列

}


