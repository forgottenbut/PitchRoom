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
   
    int print_count = 0; // 用于记录已经打印的冒泡操作次数
    int temp; // 用于交换的临时变量

    for (int i = 0; i < n - 1; i++) { // 外层循环控制冒泡次数
        int flag = 0; // 标志位，用于优化冒泡排序
        for (int j = 0; j < n - 1 - i; j++) { // 内层循环进行冒泡操作
            if (arr[j] > arr[j + 1]) { // 如果相邻两个元素逆序
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1; // 发生交换，设置标志位
            }
        }
        if (flag == 0) { // 如果没有发生交换，说明数组已经有序
            break;
        }
        print_count++; // 每完成一次冒泡操作，打印次数加1
        if (print_count <= 3) { // 如果是前三次冒泡操作，打印当前数组状态
            print_array(arr, n);
        }
    }
    if (print_count < 3) { // 如果数组长度小于4，不足三次打印，打印最终结果
        for (int i = print_count; i < 3; i++) {
            print_array(arr, n);
        }
    }
    print_array(arr, n); // 最终打印升序序列
    
}


