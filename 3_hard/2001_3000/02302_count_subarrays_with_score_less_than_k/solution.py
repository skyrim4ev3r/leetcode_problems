class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:

        count = 0
        total_sum = 0
        left = 0
        right = 0
        nums_len = len(nums)

        while(True):
            while (left < nums_len and nums[left] >= k):
                left += 1

            if (left >= nums_len):
                break

            right = left
            total_sum = 0

            while (left <= right):
                while (right <  nums_len and ((total_sum + nums[right]) * (right - left + 1)) < k):
                    total_sum += nums[right]
                    right += 1

                if right == nums_len or nums[right] >= k:
                    count += ((right - left) * (right - left + 1)) // 2
                    left = right
                    break

                count += (right - left)
                total_sum -= nums[left]
                left += 1

        return count
