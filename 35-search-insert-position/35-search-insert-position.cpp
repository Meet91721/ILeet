class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0, tail = nums.size() - 1;
        int mid;
        while(head <= tail){
            mid = (head + tail) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                tail = mid - 1;
            }
            else{
                head = mid + 1;
            }
        }
        if(nums[mid] < target){
            return mid+1;
        }
        return mid;
    }
};