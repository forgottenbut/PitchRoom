def selection_sort(arr):
    # 遍历数组中的所有元素
    for i in range(len(arr)):
        # 假设当前索引的元素是最小的
        min_index = i
        # 从i+1到末尾寻找最小的元素
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        # 交换找到的最小元素和当前元素
        arr[i], arr[min_index] = arr[min_index], arr[i]

# 示例用法
arr = [64, 25, 12, 22, 11]
selection_sort(arr)
print("排序后的数组:", arr)