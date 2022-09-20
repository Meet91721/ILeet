class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(),nums.end(),target);
        if(it == nums.end() || *it != target)
            return {-1,-1};
        auto it1 = upper_bound(nums.begin(),nums.end(),target);
        
        advance(it1,-1);
        int one = distance(nums.begin(),it);
        int two = distance(nums.begin(),it1);
        return {one,two};
    }
};