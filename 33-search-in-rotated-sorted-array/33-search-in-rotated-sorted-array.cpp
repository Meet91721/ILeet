class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi = nums.size() - 1;
        int lo = 0;
        while(hi > lo){
            int mid = (hi + lo) / 2;
            if(nums[mid]>nums[hi])
                lo=mid+1;
            else
                hi=mid;
        }
        int k = lo;
        hi = nums.size() - 1;
        lo = 0;
        while(hi >= lo){
            int mid = ((hi + lo) / 2);
            int realmid = (mid + k) %nums.size();
            // cout << hi << " " << lo << " " << mid << " " << realmid << '\n';
            if(nums[realmid] > target){
                hi = mid - 1;
            }
            else if(nums[realmid] < target){
                lo = mid + 1;
            }
            else{
                return realmid;
            }
        }
        // cout << hi << " " << lo << '\n';
        // if(nums[lo] == target)
        //     return lo;
        // if(nums[hi] == target)
        //     return hi;
        return -1;
    }
};