class Solution {
public:
    
    int dp[1001];
    
    int recurse(int num, vector<int>& nums){
        if(num==0)
            return 1;
        if(num<0)
            return 0;
        if(dp[num]!=-1){
            return dp[num];
        }
        int t = 0;
        for(int i = 0; i < nums.size(); i++)
            if(num-nums[i]>=0)
                t+=recurse(num-nums[i],nums);
        
        dp[num] = t;
        return dp[num];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return recurse(target,nums);
    }
};