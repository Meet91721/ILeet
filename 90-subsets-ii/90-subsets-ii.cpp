class Solution {
public:
    
    vector<vector<int>> res;
    
    void recurse(vector<int>&nums, int index, vector<int>& temp){
        
        if(index == nums.size()){
            res.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        recurse(nums, index + 1, temp);
        temp.pop_back();
        int i = 1 + index;
        for(; i < nums.size(); i++){
            if(nums[i] == nums[index])
                continue;
            break;
        }
        recurse(nums, i, temp);
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        recurse(nums, 0, temp);
        return res;
    }
};

// 0 0 1 2 3
// 0 :(2)
// 