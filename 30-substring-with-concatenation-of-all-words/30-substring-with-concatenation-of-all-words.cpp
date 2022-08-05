class Solution {
public:
    unordered_map<string,int>mp;
    bool funcc(string &s, vector<string> &words, int index){
        int len = words[0].size();
        for(int i = index; i < index + len*words.size(); ){
            string word = s.substr(i,len);
            if(mp.find(word)==mp.end()){
                return 0;
            }
            if(mp[word]==0){
                return 0;
            }
            mp[word]--;
            i+=len;
        }
        return 1;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        vector<int>res;
        unordered_map<string,int>realMp = mp;
        for(int i = 0; i < s.length()-words[0].length()*words.size()+1; i++){
            if(funcc(s, words, i))
                res.push_back(i);
            mp = realMp;
        }
        return res;
    }
};