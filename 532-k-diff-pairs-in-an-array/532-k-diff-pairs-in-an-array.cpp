class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            auto it = lower_bound(nums.begin()+i+1,nums.end(), nums[i]+k);
            if(it == nums.end())
                continue;
            if(*it == nums[i] + k)
                res++;
                
            while(i < nums.size()-1 && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};