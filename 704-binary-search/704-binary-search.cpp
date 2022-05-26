class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head = 0, tail = nums.size() - 1;
        int mid;
        
        while(head <= tail){
            mid = (head + tail) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                tail = mid-1;
            }
            else{
                head = mid+1;
            }
        }
        // if(nums[mid] == target)
        //     return mid;
        // if((mid > 0) && (nums[mid-1] == target))
        //     return mid-1;
        return -1;
    }
};