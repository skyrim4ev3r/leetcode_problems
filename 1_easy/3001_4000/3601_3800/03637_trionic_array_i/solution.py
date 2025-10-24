class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        is_increase, change_state_count, ret_false_cond = True, 0, nums[0] >= nums[1]
        for i in range(1,len(nums)):
            if nums[i] == nums[i-1] or ret_false_cond :
                return False
            elif is_increase != (nums[i-1] < nums[i]):
                is_increase = not is_increase
                change_state_count += 1
                ret_false_cond = change_state_count > 2
        return change_state_count == 2