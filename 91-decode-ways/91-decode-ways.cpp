class Solution {
public:
    
    int dp[101];
    
    int func(int ind, string& s){
        if(ind == (int)s.length())
            return 1;
        int &t1 = dp[ind];
        if(t1!=-1)
            return dp[ind];
        if(s[ind] == '0')
            return 0;
        t1 = func(ind+1,s);
        if(ind<(int)s.length()-1){
            if(s[ind] == '2' && s[ind+1] <= '6')
                t1+=func(ind+2,s);
            else if(s[ind] == '1'){
                t1+=func(ind+2,s);
            }
        }
        return t1;
    }
    
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return func(0,s);
    }
};