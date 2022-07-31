class Solution {
public:
    
    int minDistance(string text1, string text2) {
        int dp[text1.size()+1][text2.size()+1];
        for(int i = 0; i < text1.size()+1; i++){
            for(int j = 0; j < text2.size()+1; j++){
                if(i == 0)
                {
                    dp[i][j]=j;
                    continue;
                }
                if(j==0){
                    dp[i][j]=i;
                    continue;
                }
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};