class Solution {
public:
    
    bool isPalindrome(string s){
        int hi = s.length() - 1;
        int lo = 0;
        while(hi > lo){
            if(s[hi] != s[lo]){
                return false;
            }
            hi--;
            lo++;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int hi = s.length() - 1, lo = 0;
        while(hi > lo){
            if(s[hi] != s[lo]){
                if(s[hi-1] == s[lo]){
                    // cout << "Checking: " << s.substr(lo, hi-lo) << '\n';
                    if(isPalindrome(s.substr(lo, hi - lo)))
                        return true;
                }
                if(s[lo+1] == s[hi]){
                    // lo++;
                    if(isPalindrome(s.substr(lo+1, hi - lo)))
                        return true;
                }
                return false;
            }
            hi--;
            lo++;
        }
        return true;
    }
};