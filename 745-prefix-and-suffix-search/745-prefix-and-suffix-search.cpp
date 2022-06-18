class WordFilter {
public:
    
    unordered_map<string,int>hsh;
    
    WordFilter(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            for(int j = 1; j <= words[i].size(); j++){
                string word1 = words[i].substr(0,j);
                for(int k = 0; k < words[i].size(); k++){
                    string word2 = words[i].substr(k,words[i].size());
                    hsh[word1+"|"+word2]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return hsh[prefix+"|"+suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */