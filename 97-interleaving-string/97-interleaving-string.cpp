class Solution {
public:
    
    int dp[101][101][201];
    
    bool funcc(string &s1, string &s2, string &s3, int i, int j, int k, string &res){
        if(s3 == res)
            return true;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(s1[i]==s3[k]){
            res+=s1[i];
            if(funcc(s1,s2,s3,i+1,j,k+1,res))
                return dp[i][j][k] = true;
            res.pop_back();
        }
        if(s2[j]==s3[k]){
            res+=s2[j];
            if(funcc(s1,s2,s3,i,j+1,k+1,res))
                return dp[i][j][k]=true;
            res.pop_back();
        }
        return dp[i][j][k]=false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
            return false;
        string res="";
        memset(dp,-1,sizeof(dp));
        return funcc(s1,s2,s3,0,0,0,res);
    }
};