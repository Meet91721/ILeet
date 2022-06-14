class Solution {
public:
    
    constexpr static int N = 1001;
    int mp[N][N];
    
    int recurse(string& s1, string& s2, int m, int n){
        if(m == s1.length() || n == s2.length())
            return 0;
        if(mp[m][n]!=0)
            return mp[m][n];
        if(s1[m] == s2[n]){
            mp[m][n]=1+recurse(s1,s2,m+1,n+1);
            return mp[m][n];
        }
        mp[m][n]=max(recurse(s1,s2,m+1,n),recurse(s1,s2,m,n+1));
        return mp[m][n];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        return recurse(text1,text2,0,0);
    }
};