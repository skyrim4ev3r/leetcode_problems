class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        size = len(nums) - 1
        for i in range(0,len(nums)):
            if nums[i]>0 :
                break
            if (i>0 and nums[i]==nums[i-1]) or ((nums[i]*-1)>nums[size]*2) :
                continue
            while nums[size]>0 and (nums[i]*-1)*2 < nums[size] :
                size -= 1
            k = size
            j = i + 1
            while j < k :
                t_sum = nums[i] + nums[j] + nums[k]
                if t_sum < 0 :
                    j += 1
                elif t_sum > 0 :
                    k -= 1
                else :
                    res.append([nums[i],nums[j],nums[k]])
                    while True :
                        j += 1
                        if not (j < len(nums)-1 and nums[j]==nums[j-1]) :
                            break
                    while True :
                        k -= 1
                        if not (k>0 and nums[k]==nums[k+1]) :
                            break
        return res
