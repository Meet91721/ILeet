class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<bool>vec(31,0);
        for(int i = 0; i<nums.size(); i++){
            int index = 0;
            while(nums[i]){
                if(nums[i]&1)
                    vec[index]=1;
                nums[i]>>=1;
                index++;
            }
        }
        // for(int i = 0; i < vec.size(); i++)
        //     cout << vec[i] << " \n"[i==vec.size()-1];
        int res = 0;
        int n = nums.size();
        int num = pow(2,n-1);
        for(int i = 0; i < 31; i++){
            res+=(vec[i]<<i)*num;
        }
        return res;
    }
};