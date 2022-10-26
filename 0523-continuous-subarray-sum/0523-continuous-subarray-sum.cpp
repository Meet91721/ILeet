class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        set<int>s;
        int ins = 0;
        int sum=0;
        for(int i = 0; i < (int)nums.size(); i++){
            sum+=nums[i];
            if(s.find(sum%k)!=s.end())
                return true;
            s.insert(ins);
            ins = sum%k;
        }
        return false;
    }
};