class Solution {
public:
    vector<int> diStringMatch(string s) {
        int lo = 0, hi = s.length();
        vector<int>res(s.length()+1);
        if(s[0] == 'I'){
            res[0] = lo++;
        }
        else{
            res[0] = hi--;
        }
        for(int i = 1; i < s.length(); i++){
            if(s[i] == 'I'){
                res[i] = lo++;
            }else{
                res[i] = hi--;
            }
        }
        res[s.length()] = hi;
        return res;
    }
};