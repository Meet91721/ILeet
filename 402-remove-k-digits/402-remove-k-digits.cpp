class Solution {
public:
    string removeKdigits(string num, int k) {
        multiset<int,greater<int>>s;
        for(int i = 0; i < num.size(); i++){
            while(s.size() && k){
                if(*s.begin()>num[i]){
                    s.erase(s.begin());
                    k--;
                }
                else
                    break;
            }
            s.insert(num[i]);
        }
        while(k){
            s.erase(s.begin());
            k--;
        }
        string res;
        for(int i = num.size()-1; i >= 0; i--){
            auto it = s.find(num[i]);
            if(it == s.end())
                continue;
            res+=num[i];
            s.erase(it);
        }
        reverse(res.begin(),res.end());
        int index = 0;
        while(res[index]=='0'){
            index++;
        }
        res = res.substr(index);
        if(res == "")
            res = "0";
        return res;
    }
};