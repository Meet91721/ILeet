class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>>g;
        if(count(wordList.begin(),wordList.end(),beginWord)==0){
            wordList.push_back(beginWord);
        }
        
        queue<string>q;
        q.push(beginWord);
        unordered_map<string,int>dist;
        dist[beginWord]=1;
        while(q.size()){
            string curr = q.front();
            q.pop();
            
            for(int i = 0; i < wordList.size(); i++){
                int diff = 0;
                for(int x = 0; x < curr.length(); x++)
                    if(curr[x] != wordList[i][x])
                        diff++;
                if(diff!=1)
                    continue;
                
                if(dist.find(wordList[i])!=dist.end())
                    continue;
                q.push(wordList[i]);
                dist[wordList[i]]=dist[curr]+1;
                if(wordList[i] == endWord)
                    return dist[wordList[i]];
            }
        }
        return 0;
    }
};