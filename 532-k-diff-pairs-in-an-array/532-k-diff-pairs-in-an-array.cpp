class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int low = i+1, high = nums.size()-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(nums[mid]==nums[i]+k){
                    res++;
                    break;
                }
                else if(nums[mid] > nums[i]+k){
                    high = mid-1;
                }
                else
                    low = mid+1;
            }
            while(i < nums.size()-1 && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};