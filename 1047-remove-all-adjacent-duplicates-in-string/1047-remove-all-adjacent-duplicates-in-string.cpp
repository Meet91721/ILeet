class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>stk;
        for(int i = 0; i < s.length(); i++){
            if(stk.size() == 0){
                stk.push(s[i]);
            }
            else{
                if(stk.top() == s[i])
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        s="";
        while(stk.size()){
            s+=stk.top();
            stk.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};