class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>>mp;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>>res;
        for(auto it: mp){
            res.push_back({});
            vector<int>&indexes = it.second;
            for(int i = 0; i < indexes.size(); i++){
                res.back().push_back(strs[indexes[i]]);
            }
        }
        return res;
    }
};