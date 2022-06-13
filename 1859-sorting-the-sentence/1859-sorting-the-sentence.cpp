class Solution {
public:
    string sortSentence(string s) {
        map<int,string>mp;
        size_t index = s.find(' ');
        size_t l = 0;
        int i = 1;
        while(index != string::npos){
            mp[stoi(s.substr(index-1,1))] = s.substr(l, index - 1 - l);
            l = index+1;
            index = s.find(' ', index+1);
            i++;
        }
        mp[stoi(s.substr(s.length()-1))] = s.substr(l, s.length()-1-l);
        string res = "";
        for(auto it: mp){
            res+=it.second+" ";
        }
        return res.substr(0,res.length()-1);
    }
};