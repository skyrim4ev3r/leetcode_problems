class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto total_count = nums1.size() + nums2.size();
        auto left_count = (total_count)/2;
        auto right_count = left_count + 1;
        int left_val = 0;
        if(left_count * 2 != total_count) {
        	left_count += 1;
        }
        decltype(nums1.size()) count1 = 0, count2 = 0;
        bool last_nums1 = false;
        while(count1 < nums1.size() || count2 < nums2.size()){          
            if(count1 < nums1.size() && count2 < nums2.size()) {
                if(nums1[count1]< nums2[count2]) {
                    count1 += 1;
                    last_nums1 = true;
                } else {
                    count2 += 1;
                    last_nums1 = false;
                }
            }
            else if(count1<nums1.size()) {
                count1 += 1;
                last_nums1 = true;
            } else {
                count2 += 1;
                last_nums1 = false;
            }
            auto current_count = count1 + count2;
            if(current_count == left_count){
                if(last_nums1) {
                    left_val = nums1[count1-1];
                } else {
                    left_val = nums2[count2-1];
                }
            }
            if(current_count == right_count) {
                if(last_nums1) {
                    return static_cast<double>((left_val + nums1[count1 - 1])) / 2.0;
                } else {
                    return static_cast<double>((left_val + nums2[count2-1]))/ 2.0;
                }
            }
        }
        return 0.0;
    }
};
