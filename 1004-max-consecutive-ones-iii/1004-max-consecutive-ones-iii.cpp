class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, zerosCnt = 0, res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==0){
                zerosCnt++;
            }
            if(zerosCnt>k){
                while(zerosCnt>k){
                    if(nums[l]==0)
                        zerosCnt--;
                    l++;
                }
            }
            res = max(res,i-l+1);
        }
        return res;
    }
};