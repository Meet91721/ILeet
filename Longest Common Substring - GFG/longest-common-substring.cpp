//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int dp[1100][1001];
    
    int func(int i, int j, string &a, string &b){
        if(i == a.size() || j == b.size())
            return 0;
        if(dp[i][j] != -1)
        return dp[i][j];
        if(a[i] == b[j])
            return dp[i][j] = 1 + func(i+1, j+1,a, b);
        return dp[i][j] = 0;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i = 0; i < n; i+=1){
            for(int j = 0; j < m; j++){
                ans = max(ans, func(i, j, S1, S2));
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends