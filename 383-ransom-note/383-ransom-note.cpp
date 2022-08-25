class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>hsh(26,0);
        for(int i = 0; i < magazine.size(); i++){
            hsh[magazine[i]-'a']++;
        }
        for(int i = 0; i < ransomNote.size(); i++){
            if(--hsh[ransomNote[i]-'a']<0)
                return false;
        }
        return true;
    }
};