class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int current;
        for(int i = 0; i < size - 2;){
            current = nums[i];
            int index = i + 1;
            int lindex = size - 1;
            int first = nums[index];
            int second = nums[lindex];
            while(index < lindex){
                if(first + second == -current){
                    vector<int> temp{current, first, second};
                    index++;
                    lindex--;
                    while(nums[index] == first && index < lindex){
                        index++;
                    }
                    first = nums[index];
                    while(nums[lindex] == second && index < lindex){
                        lindex--;
                    }
                    second = nums[lindex];
                    res.push_back(temp);
                }
                else{
                    // index++;
                    // if(index < lindex)
                    //     first = nums[index];
                    // else{
                    //     break;
                    // }
                    if(first + second < -current){
                        index++;
                    }else if(first + second > -current){
                        lindex--;
                    }else{
                        index++;
                        lindex--;
                    }
                    if(index < lindex){
                        first = nums[index];
                        second = nums[lindex];
                    }else{
                        break;
                    }
                }
            }
            while(i < (size - 2) && nums[i] == current){
                i++;
            }
        }
        return res;
    }
};