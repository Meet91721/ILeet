class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trustIn[n+1];
        unordered_set<int>trustsSomeone;
        
        for(int i = 0; i < trust.size(); i++){
            trustIn[trust[i][1]].push_back(trust[i][0]);
            trustsSomeone.insert(trust[i][0]);
        }
        for(int i = 1; i <= n; i++){
            if(trustIn[i].size() == n - 1){
                if(trustsSomeone.find(i) == trustsSomeone.end())
                    return i;
            }
        }
        return -1;
        
    }
};