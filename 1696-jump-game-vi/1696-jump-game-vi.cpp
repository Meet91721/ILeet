class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        set<pair<int,int>,greater<pair<int,int>>>s;
        int index = 1;
        s.insert({nums[0],0});
        for(; index < nums.size(); index++){
            while(s.begin()->second<index-k){
                s.erase(s.begin());
            }
            if(index == nums.size()-1){
                return s.begin()->first+nums[index];
            }
            s.insert({s.begin()->first+nums[index],index});
        }
        return nums[nums.size()-1];
    }
};