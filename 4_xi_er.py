def shell_sort(arr):
    n = len(arr)
    gap = n // 2  # 初始间隔
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # 对间隔为 gap 的元素进行插入排序
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2  # 缩小间隔
    return arr

# 测试
arr = [12, 34, 54, 2, 3]
print("希尔排序结果:", shell_sort(arr))