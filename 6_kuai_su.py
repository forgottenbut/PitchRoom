def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]  # 选择基准值
    left = [x for x in arr if x < pivot]  # 小于基准值的部分
    middle = [x for x in arr if x == pivot]  # 等于基准值的部分
    right = [x for x in arr if x > pivot]  # 大于基准值的部分
    return quick_sort(left) + middle + quick_sort(right)  # 递归排序

# 测试
arr = [10, 7, 8, 9, 1, 5]
print("快速排序结果:", quick_sort(arr))