class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>hsh(26,0);
        for(int i = 0; i < words2.size(); i++){
            vector<int>temp(26,0);
            for(int j = 0; j < words2[i].length(); j++){
                temp[words2[i][j]-'a']++;
            }
            for(int j = 0; j < 26; j++){
                hsh[j] = max(hsh[j], temp[j]);
            }
        }
        vector<string>res;
        for(int i = 0; i < words1.size(); i++){
            vector<int>temp(26,0);
            for(int j = 0; j < words1[i].length(); j++){
                temp[words1[i][j]-'a']++;
            }
            bool found = true;
            for(int j = 0; j < 26; j++){
                if(temp[j]<hsh[j]){
                    found = false;
                    break;
                }
            }
            if(found)
                res.push_back(words1[i]);
        }
        return res;
    }
};