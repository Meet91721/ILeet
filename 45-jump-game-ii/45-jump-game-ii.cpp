class Solution {
public:
    
    int res = 0;
    
    void recurse(vector<int>& nums, int index){
        if(index == 0)
            return;
        for(int i = 0; i < index; i++){
            if(nums[i] + i>=index)
            {
                res++;
                recurse(nums, i);
                return;
            }
        }
    }
    
    int jump(vector<int>& nums) {
        recurse(nums, nums.size() - 1);
        return res;
    }
};