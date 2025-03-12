def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i  # 假设当前是最小值
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j  # 更新最小值索引
        arr[i], arr[min_idx] = arr[min_idx], arr[i]  # 交换
    return arr

# 测试
arr = [64, 25, 12, 22, 11]
print("选择排序结果:", selection_sort(arr))