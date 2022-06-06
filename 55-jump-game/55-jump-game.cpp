class Solution {
public:
    
    
    //BRO why DP?? This is simple max element problem
    /*
    map<int,bool>mp;
    
    bool recurse(vector<int>& nums, int node){
        if(node >= nums.size()){
            return false;
        }
        if(node == nums.size() - 1){
            return true;
        }
        if(mp.find(node) != mp.end()){
            return mp[node];
        }
        bool temp = false;
        for(int i = 1; i <= nums[node]; i++){
            temp = temp | recurse(nums, node+i);
        }
        mp[node] = temp;
        return temp;
    }
    */
    
    bool canJump(vector<int>& nums) {
        int limit = nums[0];
        int size = nums.size();
        // if(limit>=size-1)
        //     return true;
        for(int i = 0; i <= limit; i++){
            if(limit>=size - 1)
                return true;
            if(i+nums[i]>limit)
                limit = i+nums[i];
        }
        return false;
    }
};