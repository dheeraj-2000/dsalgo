import math
import heapq

def minSum(number, k):
    heap = number
    heapq._heapify_max(heap)

    for i in range(k):
        max_val = heap[0]
        if max_val == 1:
            break
        new_val = (max_val >> 1) + (max_val & 1)
        replace_max(heap, new_val)

    return sum(heap)
n, k = map(int,input().split())
number = list(map(int,input().split()))

s = minSum(number,k)
print(s)
