class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int leng = s.length();
        
        unordered_set<string>st;
        for(int i = 0; i < leng-k+1; i++){
            st.insert(s.substr(i,k));
        }
        
        if(st.size() >= (2<<(k-1))){
            return true;
        }
        return false;
    }
};