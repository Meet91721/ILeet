class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        set<int>s;
        int last = 0;
        map<int,int>mp;
        int atmostK = 0, atmostkm1;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            s.insert(nums[i]);
            while(s.size()>k){
                mp[nums[last]]--;
                last++;
                if(mp[nums[last-1]] == 0){
                    s.erase(nums[last-1]);
                    break;
                }
            }
            int temp = (i-last+1);
            atmostK+=temp;
        }
        mp.clear();
        last=0;
        s.clear();
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            s.insert(nums[i]);
            while(s.size()>k-1){
                mp[nums[last]]--;
                last++;
                if(mp[nums[last-1]] == 0){
                    s.erase(nums[last-1]);
                    break;
                }
            }
            int temp = (i-last+1);
            atmostkm1+=temp;
        }
        return atmostK-atmostkm1;
    }
};