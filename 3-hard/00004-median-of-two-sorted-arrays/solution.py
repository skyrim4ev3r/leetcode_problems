class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        total_count = len(nums1) + len(nums2)
        left_count = (total_count)//2
        right_count = left_count + 1
        left_val = 0
        if left_count * 2 != total_count:
        	left_count += 1
        count1, count2, last_nums1 = 0, 0, False
        while count1 < len(nums1) or count2 < len(nums2):
            if count1 < len(nums1) and count2 < len(nums2):
                if nums1[count1]< nums2[count2]:
                    count1 += 1
                    last_nums1 = True
                else:
                    count2 += 1
                    last_nums1 = False
            elif count1<len(nums1):
                count1 += 1
                last_nums1 = True
            else:
                count2 += 1
                last_nums1 = False
            current_count = count1 + count2
            if current_count == left_count:
                if last_nums1:
                    left_val = nums1[count1-1]
                else:
                    left_val = nums2[count2-1]
            if current_count == right_count:
                if last_nums1:
                    return (left_val + nums1[count1 - 1]) / 2.0
                else:
                    return (left_val + nums2[count2-1]) / 2.0
        return 0.0
