class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool found = false;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1])
            {
                if(found)
                    return false;
                found = true;
                if(i == 0)
                    continue;
                if(i == nums.size() - 2)
                    return true;
                if((nums[i-1]>nums[i+1]) && (nums[i]>nums[i+2]))
                    return false;
            }
        }
        return true;
    }
};