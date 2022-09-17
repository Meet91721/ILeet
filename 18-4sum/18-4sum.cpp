class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(long long i = 0; i < (long long)nums.size(); i++){
            if(nums[i] > target && nums[i]>=0)
                return res;    
            for(long long j = i+1; j < (long long)nums.size()-2; j++){
                if(nums[j] + nums[i] > target && nums[j]>=0)
                    break;
                long long low = j+1, high = (long long)nums.size()-1;
                while(high>low){
                    long long sum=1LL*nums[i] + nums[j] + nums[low]+nums[high];
                    
                    if(sum < target){
                        low++;
                    }
                    else if(sum > target){
                        high--;
                    }
                    else{
                        res.push_back({nums[i],nums[j],nums[low],nums[high]});
                        long long temp = nums[low];
                        while(low < high && temp == nums[low])
                            low++;
                        temp = nums[high];
                        while(low < high && temp == nums[high])
                            high--;
                    }
                }
                while(j < (long long)nums.size()-1 && nums[j] == nums[j+1])
                    j++;
            }
            while(i < (long long)nums.size()-1 && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};