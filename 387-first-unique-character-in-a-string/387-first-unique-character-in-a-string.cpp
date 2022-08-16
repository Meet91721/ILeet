class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>hsh(26,0);
        for(int i = 0; i < s.length(); i++)
            hsh[s[i]-'a']++;
        for(int i = 0; i < s.length(); i++){
            if(hsh[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};