class Solution {
public:
    
    const int MOD = 1e9+7;
    
    const static int sze = 2e5;
    long long int dp[sze];
    
    long long int func(int ind, string &s){
        if(ind == (int)s.length())
            return 1;
        if(s[ind] == '0')
            return 0;
        long long int &t = dp[ind];
        if(t!=-1)
            return t;
        if(s[ind] == '*'){
            t = (9LL*func(ind+1,s))%MOD;
            if(ind<(int)s.length()-1){
                if(s[ind+1] == '*'){
                    t=(t+(15LL*func(ind+2,s))%MOD)%MOD;
                }
                else if(s[ind+1] <= '6'){
                    t=(t+(2LL*func(ind+2,s))%MOD)%MOD;
                }
                else{
                    t=(t+func(ind+2,s))%MOD;
                }
            }
            return t;
        }
        t = func(ind+1,s);
        if(ind<(int)s.length()-1){
            if(s[ind]=='2' && s[ind+1] <= '6' && s[ind+1]!='*'){
                t=(t+func(ind+2,s))%MOD;
            }
            else if(s[ind] == '1' && s[ind+1] != '*'){
                t=(t+func(ind+2,s))%MOD;
            }
            else if(s[ind+1] == '*'){
                if(s[ind] == '2'){
                    t=(t+6LL*func(ind+2,s))%MOD;
                }
                else if(s[ind] == '1')
                    t=(t+(9LL*func(ind+2,s))%MOD)%MOD;
            }
        }
        return t;
    }
    
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return func(0,s);
    }
};