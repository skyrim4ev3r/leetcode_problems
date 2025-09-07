class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int size = nums.size()-1;
        for(int i{0};i<nums.size() && nums[i]<=0 ;++i)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            if((nums[i]*-1)>nums[size]*2)
                continue;            
            while(nums[size]>0 && (nums[i]*-1)*2 < nums[size])
                size--;
            int k=size;
            int j{i+1};
            while(j<k)
            {
                int sum =nums[i]+nums[j]+nums[k];
                if(sum<0)
                    ++j;
                else if(sum>0)
                    --k;
                else
                {
                    res.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    do{
                        ++j;
                    }while(j < nums.size()-1 && nums[j]==nums[j-1]);
                    do{
                        --k;
                    }while(k>0 && nums[k]==nums[k+1] );                   
                }
            } 
        }     
        return res;
    }
};
