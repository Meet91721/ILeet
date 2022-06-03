class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int i = 2;
        for(; (i < nums.size()); i++){
             if(nums[i-1]+nums[i]>nums[i-2]){
                 return nums[i-1]+nums[i]+nums[i-2];
             }
        }
        return 0;
    }
};