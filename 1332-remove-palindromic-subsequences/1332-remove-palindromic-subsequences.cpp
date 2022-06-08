class Solution {
public:
    
    bool isPalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        if(s.length() == 0)
            return 0;
        if(isPalindrome(s, 0, s.length()-1))
            return 1;
        return 2;
    }
};

/**/