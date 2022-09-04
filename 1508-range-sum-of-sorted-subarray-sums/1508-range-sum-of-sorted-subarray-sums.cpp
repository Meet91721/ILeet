class Solution {
public:
    int M = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long int>s;
        for(int i = 0; i < n; i++){
            int temp = nums[i];
            for(int j = i; j < n; j++){
                if(i!=j)
                    temp=(temp+nums[j])%M;
                s.push_back(temp);
            }
        }
        sort(s.begin(),s.end());
        // for(int i = 0; i < s.size(); i++)
        //     cout << s[i] << " ";
        for(int i = 1; i < s.size(); i++){
            s[i] = (s[i]+s[i-1])%M;
        }
        // for(int i = 0; i < s.size(); i++)
        //     cout << s[i] << " ";
        if(left==1)
            return s[right-1];
        return s[right-1]-s[left-2];
    }
};