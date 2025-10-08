class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        for i in range(len(nums) - 1,0, -1):
            temp = [None] * i
            for j in range(len(nums) - 1):
                temp[j] = (nums[j] + nums[j+1]) % 10
            nums = temp
        print(len(nums))
        return nums[0]