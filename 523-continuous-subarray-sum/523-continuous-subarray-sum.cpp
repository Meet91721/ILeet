class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==1)
            return false;
        map<int,int>mp;
        mp[0]=-1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
            auto it = mp.find(sum%k);
            if(it == mp.end())
                mp[sum%k]=i;
            else{
                if(mp[sum%k]==i-1)
                    continue;
                else
                    return true;
            }
        }
        return false;
    }
};