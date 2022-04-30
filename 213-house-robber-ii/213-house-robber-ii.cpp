class Solution {
public:
    
    map<int,int> memoize1;
    map<int,int> memoize0;
    
    int funcc(int n, int curr_house, vector<int>& houses, int check){
        if(!check)
            cout << curr_house << "\n";
        if(check && (curr_house > n - 1) && n != 1)
            return 0;
        if(curr_house > n){
            return 0;
        }
        
        if(check){
            auto it = memoize1.find(curr_house);
            if(it == memoize1.end()){
                memoize1[curr_house] = houses[curr_house-1] + max(funcc(n,curr_house+2, houses, check), funcc(n,curr_house+3,houses, check));
            }
            return memoize1[curr_house];    
        }
        
        auto it = memoize0.find(curr_house);
        if(it == memoize0.end()){
            memoize0[curr_house] = houses[curr_house-1] + max(funcc(n,curr_house+2, houses, check), funcc(n,curr_house+3,houses, check));
        }
        return memoize0[curr_house];
        
    }
    
    int rob(vector<int>& nums) {
        int res = max({funcc(nums.size(), 1, nums, 1), funcc(nums.size(), 2, nums, 0), funcc(nums.size(), 3, nums, 0)});
        // for(auto it : memoize){
        //     // cout << it.first << " " << it.second << "\n";
        // }
        return res;
    }
};