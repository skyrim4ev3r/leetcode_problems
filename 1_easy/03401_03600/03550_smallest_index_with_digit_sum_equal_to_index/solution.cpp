class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i{0}; i < nums.size(); ++i){
            int index{i}, value{nums[i]};
            while(value > 0){
                index -= value % 10;
                value /= 10;
            }
            if(index == 0)
                return i;
        }
        return -1;
    }
};
