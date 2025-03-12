def heapify(arr, n, i):
    largest = i  # 初始化最大值为根节点
    left = 2 * i + 1
    right = 2 * i + 2

    # 如果左子节点存在且大于根节点
    if left < n and arr[i] < arr[left]:
        largest = left

    # 如果右子节点存在且大于最大值
    if right < n and arr[largest] < arr[right]:
        largest = right

    # 如果最大值不是根节点
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # 交换
        heapify(arr, n, largest)  # 递归调整

def heap_sort(arr):
    n = len(arr)
    # 构建最大堆
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    # 逐个提取元素
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # 交换
        heapify(arr, i, 0)
    return arr

# 测试
arr = [12, 11, 13, 5, 6, 7]
print("堆排序结果:", heap_sort(arr))