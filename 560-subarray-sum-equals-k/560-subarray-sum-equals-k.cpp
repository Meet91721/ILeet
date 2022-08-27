class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int sum = 0;
        mp[sum]=1;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+=nums[i];
            auto it = mp.find(sum-k);
            if(it!=mp.end())
                res+=(*it).second;
            mp[sum]++;
        }
        return res;
    }
};