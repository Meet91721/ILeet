class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.length()<b.length();
        });
        int mx=0;
        unordered_map<string,int>mp;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                string temp = words[i].substr(0,j)+words[i].substr(j+1);
                if(mp.find(temp) == mp.end()){
                    mp[words[i]]=max(mp[words[i]],1);
                }
                else{
                    mp[words[i]]=max(mp[words[i]],1+mp[temp]);
                }
            }
        }
        
        // for(auto it: mp){
        //     cout << it.first << " " << it.second << '\n';
        // }

        return max_element(mp.begin(),mp.end(), [](const pair<string,int>&a,const pair<string,int>&b){
            return a.second<b.second;
        })->second;
    }
};