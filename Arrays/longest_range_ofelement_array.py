
def longest_range(array):
    lar_range = []
    max_lenth = 0
    map_num = {}
    for num in array:
        map_num[num] = True
    for num in array:
        if not map_num[num]:
            continue
        else:
            map_num[num] = False
            current_count = 1
            left = num-1
            right = num+1
            while left in map_num:
                map_num[left] = False
                current_count+=1
                left -= 1
            while right in map_num:
                map_num[right] = False
                current_count += 1
                right += 1
            if current_count >max_lenth:
                max_lenth = current_count
                lar_range = [left+1, right-1]

    print(max_lenth, lar_range)

longest_range([1,11,3,0, 15, 5, 2, 4, 10, 7, 12, 6])
