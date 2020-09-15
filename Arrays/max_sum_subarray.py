from sys import maxsize
def max_sum_subarr(list1, size):
    curr_max=list1[0]
    global_max=list1[0]
    for each in range(1, size):
        curr_max = max(list1[each], curr_max+list1[each])
        global_max = max(global_max, curr_max)
    return global_max

n = int(input())
list1 = []
for i in range(0,n):
    num = int(input())
    list1.append(num)


print(max_sum_subarr(list1, len(list1)))
# print(len(list1))
