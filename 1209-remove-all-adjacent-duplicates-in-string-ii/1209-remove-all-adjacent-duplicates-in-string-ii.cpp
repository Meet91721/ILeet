class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>stk;
        for(int i = 0; i < s.length(); i++){
            if(stk.size()==0){
                stk.push({s[i],1});
            }
            else{
                char ch = stk.top().first;
                if(ch==s[i])
                    stk.top().second++;
                else
                    stk.push({s[i],1});
            }
            while(stk.size() && stk.top().second>=k){
                stk.top().second-=k;
                if(stk.top().second == 0)
                    stk.pop();
            }
        }
        s="";
        while(stk.size()){
            for(int i = 0; i < stk.top().second; i++){
                s+=stk.top().first;
            }
            stk.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};