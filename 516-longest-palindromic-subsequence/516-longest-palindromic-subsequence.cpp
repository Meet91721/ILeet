class Solution {
public:
    
    int funcc(string& s, int n, int m, vector<vector<int>>&v){
        if(n>m)
            return 0;
        if(n==m)
            return 1;
        if(v[n][m]!=-1)
            return v[n][m];
        if(s[n]==s[m]){
            v[n][m] = 2+funcc(s,n+1,m-1,v);
            return v[n][m];
        }
        v[n][m] = max(funcc(s,n+1,m,v),funcc(s,n,m-1,v));
        
        return v[n][m];
    }
    
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>sq(s.length(),vector<int>(s.length(),-1));
        return funcc(s,0,s.length()-1,sq);
        
    }
};