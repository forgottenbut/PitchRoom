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

void adjustHeap(int *arr, int i, int n)
// 编程实现堆的调整
{
    
    int temp = arr[i]; // 当前节点
    for (int k = 2 * i + 1; k < n; k = 2 * k + 1) {
        // 从i节点的左子节点开始
        if (k + 1 < n && arr[k] < arr[k + 1]) {
            // 如果左子节点小于右子节点，k指向右子节点
            k++;
        }
        if (arr[k] > temp) {
            // 如果子节点大于父节点，将子节点值赋给父节点
            arr[i] = arr[k];
            i = k;
        } else {
            break;
        }
    }
    arr[i] = temp; // 将temp值放到最终的位置
    /********** End **********/
}

int* heap_sort(int *arr, int n)
//  基于adjustHeap函数编程实现堆排序
//  函数参数：无序数组arr 数组长度n
//  函数返回值：返回从小到大排序后的数组
{
   
    // 构建大顶堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjustHeap(arr, i, n);
    }

    // 逐步交换堆顶元素和末尾元素，并调整堆
    for (int i = n - 1; i > 0; i--) {
        // 交换堆顶元素和末尾元素
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 调整堆
        adjustHeap(arr, 0, i);
    }

    return arr;
    
}