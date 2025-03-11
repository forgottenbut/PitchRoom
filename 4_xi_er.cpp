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
    int gaps[] = {5, 2, 1}; // 增量序列
    int gap_count = sizeof(gaps) / sizeof(gaps[0]);

    for (int i = 0; i < gap_count; i++) {
        int gap = gaps[i];
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int k;
            for (k = j; k >= gap && arr[k - gap] > temp; k -= gap) {
                arr[k] = arr[k - gap];
            }
            arr[k] = temp;
        }
        print_array(arr, n); // 输出每次增量排序后的数组
    }
    print_array(arr, n);

}