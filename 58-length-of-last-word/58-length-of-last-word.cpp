class Solution {
public:
    int lengthOfLastWord(string s) {
        int spaces = 0;
        for(int i = s.length() - 1; i>=0; i--){
            if(s[i]!=' ')
                break;
            spaces++;
        }
        s = s.substr(0,s.length()-spaces);
        int l = 0;
        // trim_left(s);
        // trim_right(s);
        int found = s.find(' ');
        while(found != string::npos){
            l=found+1;
            found = s.find(' ',found+1);
        }
        // cout << s.length() << " " << l << " " << spaces << '\n';
        return s.length() - l;
    }
};