class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if(nums.size())
        //     return 0;
        unordered_set<int>s;
        for(auto it: nums){
            s.insert(it);
        }
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]-1)!=s.end())
                continue;
            int t = nums[i]+1;
            while(s.find(t)!=s.end()){
                t++;
            }
            cnt=max(cnt,t-nums[i]);
        }
        return cnt;
    }
};