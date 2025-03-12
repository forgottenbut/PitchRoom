def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]  # 当前需要插入的元素
        j = i-1
        # 将比 key 大的元素向后移动
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key  # 插入 key
    return arr

# 测试
arr = [12, 11, 13, 5, 6]
print("插入排序结果:", insertion_sort(arr))