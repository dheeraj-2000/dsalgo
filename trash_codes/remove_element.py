class Solution:
    # def removeElement(self, nums: List[int], val: int) -> int:
    def removeElement(self, nums, val):
        nums[:] = [x for x in nums if x != val]
        return len(nums)
