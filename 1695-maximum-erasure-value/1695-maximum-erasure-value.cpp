class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        vector<int> hash(10010,0);
        int sum = 0;
        int mx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(hash[nums[i]]){
                while(nums[l] != nums[i]){
                    hash[nums[l]]=0;
                    sum-=nums[l];
                    l++;
                }
                l++;
                mx = max(sum, mx);
                r++;
                continue;
            }
            hash[nums[i]] = 1;
            sum+=nums[r++];
            mx=max(sum,mx);
        }
        return mx;
    }
};