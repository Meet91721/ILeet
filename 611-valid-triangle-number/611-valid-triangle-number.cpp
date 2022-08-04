class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int sum = nums[j] + nums[i];
                auto it = lower_bound(nums.begin()+j, nums.end(),sum);
                // cout << 
                int t = distance(nums.begin()+j+1,it);
                if(t>=0)
                    res+=t;
            }
        }
        return res;
    }
};