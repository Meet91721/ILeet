class Solution {
public:
    int minSteps(string s, string t) {
        unordered_multiset<char> st;
        for(int i = 0; i < s.length(); i++){
            st.insert(s[i]);
        }
        for(int i = 0; i < t.length(); i++){
            auto it = st.find(t[i]);
            if(it!=st.end())
                st.erase(it);
        }
        return st.size();
        
    }
};