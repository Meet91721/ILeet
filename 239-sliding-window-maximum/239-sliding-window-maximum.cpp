class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int l = 0;
        int r = 0;
        multiset<int,greater<int>>s;
        vector<int> res;
        
        for(; r < nums.size() && r < k; r++){
            s.insert(nums[r]);
        }
        
        res.push_back(*s.begin());
        for(; r < nums.size(); r++){
            // auto it = 
            s.insert(nums[r]);
            auto it = s.find(nums[l]);
            s.erase(it);
            res.push_back(*s.begin());
            l++;
        }
        
        return res;
    }
};