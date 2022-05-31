class Solution {
public:
    string reverseWords(string s) {
        char c = ' ';
        size_t found = s.find(c);
        int temp = -1;
        while(found!= string::npos){
            found = s.find(c,temp+1);
            if(found == string::npos){
                break;
            }
            // cout << found << " " << 1+temp << '\n';
            reverse(s.begin() + temp+1, s.begin() + found);
            temp = found;
        }
        reverse(s.begin() + temp+1, s.end());
        return s;
    }
};