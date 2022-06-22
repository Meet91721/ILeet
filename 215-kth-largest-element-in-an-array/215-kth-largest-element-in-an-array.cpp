class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>>s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        auto it = s.begin();
        advance(it,k-1);
        return *it;
    }
};