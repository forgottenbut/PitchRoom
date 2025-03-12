def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        # 标记是否发生交换
        swapped = False
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]  # 交换
                swapped = True
        # 如果没有发生交换，说明已经有序
        if not swapped:
            break
    return arr

# 测试
arr = [64, 34, 25, 12, 22, 11, 90]
print("冒泡排序结果:", bubble_sort(arr))