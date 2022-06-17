class Solution {
public:
    
    vector<string> res;
    
    void funcc(int n, int m, string &s){
        if(n==0&&m==0){
            res.push_back(s);
            return;
        }
        if(n>0){
            s+='(';
            funcc(n-1,m+1,s);
            s.pop_back();
        }
        if(m>0){
            s+=')';
            funcc(n,m-1,s);
            s.pop_back();
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        string s;
        funcc(n,0,s);
        return res;
    }
};