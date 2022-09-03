class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>v(matrix.size(),0);
        set<tuple<int,int,int>>ms;
        for(int i = 0; i < matrix.size(); i++)
            ms.insert({matrix[i][0], i, 0});
        int ans;
        for(int i = 0; i < k; i++){
            auto [a,b,c] = *ms.begin();
            ms.erase(ms.begin());
            ans=a;
            if(c+1<matrix.size())
                ms.insert({matrix[b][c+1],b,c+1});
        }
        return ans;
    }
};