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

int partition_array(int *arr, int l, int r)
// 编程实现arr[l, r]分区：选定一个基准，左边比基准小，右边比基准大
// 返回基准所处位置
{
    
    int pivot = arr[l]; // 选择第一个元素作为基准
    int i = l + 1;
    int j = r;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 将基准值放到正确的位置
    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j;
    
}

int* quick_sort(int *arr, int l, int r)
//  基于partition_array函数编程实现快速排序：自上而下的递归方法
//  函数参数：有序数组arr 初始l=0，r=n-1
//  函数返回值：返回从小到大排序后的数组
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (l < r) {
        int p = partition_array(arr, l, r);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
    }
    return arr;
    
}