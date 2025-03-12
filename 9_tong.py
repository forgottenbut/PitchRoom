def bucket_sort(arr):
    # 创建桶
    bucket = [[] for _ in range(10)]
    # 将元素分配到桶中
    for num in arr:
        index = num // 10  # 根据范围分配
        bucket[index].append(num)
    # 对每个桶排序
    for i in range(len(bucket)):
        bucket[i] = sorted(bucket[i])
    # 合并桶
    sorted_arr = []
    for sublist in bucket:
        sorted_arr.extend(sublist)
    return sorted_arr

# 测试
arr = [29, 25, 3, 49, 9, 37, 21, 43]
print("桶排序结果:", bucket_sort(arr))