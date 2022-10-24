class Solution {
public:
    
    int res;
    
    void func(int i, vector<string>&arr, vector<vector<int>>&hsh, vector<int>&v){
        res = max(res,accumulate(v.begin(),v.end(),0));
        // cout << i << " " << res << '\n';
        if(i == arr.size())
            return;
        func(i+1,arr,hsh,v);
        bool erase = false;
        for(int j = 0; j < arr[i].size(); j++){
            v[arr[i][j]-'a']++;
            if(v[arr[i][j]-'a']>1)
                erase = true;
        }
        if(!erase)
            func(i+1,arr,hsh,v);
        for(int j = 0; j < arr[i].size(); j++){
            v[arr[i][j]-'a']--;
        }
    }
    
    int maxLength(vector<string>& arr) {
        vector<vector<int>>hsh(arr.size(),vector<int>(26,0));
        for(int i = 0; i < (int)arr.size(); i++){
            for(int j = 0; j < (int)arr[i].length(); j++){
                hsh[i][arr[i][j]-'a']++;
            }
        }
        vector<int>v(26,0);
        func(0,arr,hsh,v);
        return res;
    }
};