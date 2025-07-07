class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()

        middle = len(nums) // 2

        return nums[middle]
        