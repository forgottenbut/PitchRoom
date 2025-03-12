def counting_sort(arr):
    max_val = max(arr)
    count = [0] * (max_val + 1)

    # 统计每个元素的出现次数
    for num in arr:
        count[num] += 1

    # 生成排序后的数组
    sorted_arr = []
    for i in range(len(count)):
        sorted_arr.extend([i] * count[i])
    return sorted_arr

# 测试
arr = [4, 2, 2, 8, 3, 3, 1]
print("计数排序结果:", counting_sort(arr))