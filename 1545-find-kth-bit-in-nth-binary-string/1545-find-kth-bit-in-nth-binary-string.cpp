class Solution {
public:
    
    string funcc(string& s){
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='1')
                s[i]='0';
            else
                s[i]='1';
        }
        reverse(s.begin(),s.end());
        return s;
    }
    
    string recurse(int i){
        if(i == 0)
            return "0";
        string s = recurse(i-1);
        return s+"1"+funcc(s);
    }
    
    char findKthBit(int n, int k) {
        return recurse(n)[k-1];
    }
};