def counting_sort_for_radix(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    # 统计每个数字的出现次数
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1

    # 计算累加值
    for i in range(1, 10):
        count[i] += count[i - 1]

    # 生成输出数组
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    # 将结果复制到原数组
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    max_val = max(arr)
    exp = 1
    while max_val // exp > 0:
        counting_sort_for_radix(arr, exp)
        exp *= 10
    return arr

# 测试
arr = [170, 45, 75, 90, 802, 24, 2, 66]
print("基数排序结果:", radix_sort(arr))