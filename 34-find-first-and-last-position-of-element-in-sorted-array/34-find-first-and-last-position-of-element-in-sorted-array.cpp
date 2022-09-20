class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int one = -1;
        int high = (int)nums.size()-1, low = 0;
        while(low<=high){
            int mid = (low+high)/2;
            cout << mid;
            if(nums[mid] == target){
                high = mid-1;
                one = mid;
            }
            else if(nums[mid] < target)
                low = mid+1;
            else 
                high = mid-1;
        }
        if(one == -1)
            return {-1,-1};
        high = (int)nums.size()-1, low = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] <= target)
                low = mid+1;
            else
                high = mid-1;
        }
        return {one,low-1};
    }
};