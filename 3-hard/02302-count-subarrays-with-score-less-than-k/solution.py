class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        count, total_sum, left, right = (0, 0, 0, 0)
        while True:
            while left != len(nums) and nums[left] >= k:
                left += 1
            if left == len(nums):
                break
            right = left
            total_sum = nums[left]
            while right >= left:
                while right <  len(nums) - 1 and ((total_sum + nums[right + 1]) * (right - left + 2)) < k:
                    right += 1
                    total_sum += nums[right]
                if right == len(nums) - 1 or nums[right+1] >= k:
                    count += ((right - left + 1) * (right - left + 2))//2
                    left = right + 1
                    break
                count += right - left + 1
                total_sum -= nums[left]
                left += 1
        return count
