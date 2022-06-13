class Solution {
public:
    
    map<pair<int,int>,int>mp;
    
    int recurse(int r, int i, vector<vector<int>>&triangle){
        if(r == triangle.size() - 1){
            return triangle[r][i];
        }
        if(mp.find({r,i}) != mp.end())
            return mp[{r,i}];
        mp[{r,i}] = min(recurse(r+1,i,triangle), recurse(r+1,i+1,triangle)) + triangle[r][i];
        return mp[{r,i}];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        return recurse(0, 0, triangle);
    }
};