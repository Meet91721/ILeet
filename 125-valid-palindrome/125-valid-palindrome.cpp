class Solution {
public:
    bool isPalindrome(string s) {
        int index = 0;
        for(int i = 0; i < s.length(); i++){
            if((s[i]>='0'&&s[i]<='9') || (s[i]>='a' && s[i] <= 'z') || (s[i]>='A' && s[i] <= 'Z')){
                s[index] = tolower(s[i]);
                index++;
            }
        }
        int l = 0;
        index--;
        while(l<index){
            if(s[l]!=s[index])
                return false;
            l++;
            index--;
        }
        return true;
    }
};