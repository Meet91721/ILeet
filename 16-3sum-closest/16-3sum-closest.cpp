class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX;
        int diff = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            int low = i+1;
            int high = nums.size()-1;
            while(low < high){
                int sum = nums[i]+nums[low]+nums[high];
                if(diff > abs(target-sum)){
                    diff = abs(target-sum);
                    res = sum;
                }
                if(sum-target > 0){
                    high--;
                }
                else if(sum-target<0)
                    low++;
                else{
                    return target;
                }
            }
        }
        return res;
    }
};