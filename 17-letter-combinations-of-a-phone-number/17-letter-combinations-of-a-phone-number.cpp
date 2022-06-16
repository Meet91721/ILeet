class Solution {
public:
    
    vector<string>res;
    map<int,string>mp;
    
    void recurse(int n, string& digits, string& msg){
        if(n==digits.size()){
            if(msg == "")
                return;
            res.emplace_back(msg);
            return;
        }
        int num = digits[n]-'0';
        for(int i = 0; i < mp[num].size(); i++){
            msg+=mp[num][i];
            recurse(n+1,digits,msg);
            msg.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string ss;
        recurse(0,digits,ss);
        return res;        
    }
};