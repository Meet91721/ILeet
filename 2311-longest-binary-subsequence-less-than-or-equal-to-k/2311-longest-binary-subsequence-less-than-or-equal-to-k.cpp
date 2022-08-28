class Solution {
public:
    
    int longestSubsequence(string s, int k) {
        int value = 0;
        int i = s.length()-1;
        int digs=0;
        while(i>=0){
            if(s[i] == '0'){
                digs++;
            }
            else{
                if(digs>=31){
                    i--;
                    continue;
                }
                if(value+(1<<digs)<=k){
                    value |= (1<<digs);
                    digs++;
                }
            }
            i--;
        }
        return digs;
    }
};