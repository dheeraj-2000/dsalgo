##Approach-1:- O(n^2)time | O(1)space
def twoNumberSum(arr, targetSum):
  arr0 = 0
  for i in range(arr0, len(arr)):
      firstIndex = i
      for j in range(firstIndex, len(arr)):
          secondIndex = j
          if (arr[firstIndex] + arr[secondIndex]) == 10:
              return [arr[secondIndex], arr[firstIndex]]
  return []
 
##Run the code with some input
array = [3, 5, -4, 8, 11, 1, -1, 6]
target = 10
twoNumberSum(array, target)



##Approach-2:- O(n)time | O(n)space
def twoNumberSum(arr, targetSum):
   nums = {}
   for i in arr:
       potentialMatch = targetSum - i
       if potentialMatch in nums:
           return [potentialMatch, i]
       else:
           nums[i] = True
   return []
##Run the code with some input
array = [3, 5, -4, 8, 11, 1, -1, 6]
target = 10
twoNumberSum(array, target)


##Approach-3:- O(nlogn)time | O(1)space
def twoNumberSum(arr, targetSum):
   arr.sort()
   left = 0
   right = len(arr) - 1
   while left < right:
       currentSum = arr[left] + arr[right]
       if currentSum == targetSum:
           return[arr[left], array[right]]
       elif currentSum > targetSum:
           right-=1
       elif currentSum < targetSum:
           left += 1
   return[]
##Run the code with some input
array = [3, 5, -4, 8, 11, 1, -1, 6]
target = 10
twoNumberSum(array, target)

