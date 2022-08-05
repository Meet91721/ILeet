class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        bool rev = true;
        while(i < s.length()){
            if(rev)
                reverse(s.begin()+i,s.begin()+min(i+k,(int)s.length()));
            i+=k;
            rev = 1-rev;
        }
        return s;
    }
};