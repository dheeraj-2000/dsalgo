from typing import List
from math import inf as infinity

def max_subarray_sum(array: List[int]) -> int:
    '''
    Kadane's algorithm to find maximum subarray sum
    Time complexity: O(n)
    '''
    best_sum = -infinity
    sum_ = 0
    for item in array:
        sum_ = max(item, sum_ + item)
        best_sum = max(sum_, best_sum)
    
    return best_sum

if __name__ == '__main__':
    test = (13, -3, -25, 20, -16, -20, -25, 8, 20, -2, 11, -24, -47, 35)
    print(max_subarray_sum(test))
