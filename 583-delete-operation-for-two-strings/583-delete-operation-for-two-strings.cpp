class Solution {
public:
    
    
    
    int recurse(string s1, string s2, int m, int n, map<pair<int,int>,int>&mp){
        if(m == -1 || n == -1)
            return 0;
        if(mp.find({m,n})!=mp.end()){
            return mp[{m,n}];
        }
        if(s1[m] == s2[n]){
            mp[{m,n}]=1+recurse(s1, s2, m-1, n-1,mp);
            return mp[{m,n}];
        }
        mp[{m,n}]=max(recurse(s1,s2,m-1,n,mp),recurse(s1,s2,m,n-1,mp));
        return mp[{m,n}];
    }
    int minDistance(string word1, string word2) {
        map<pair<int,int>,int>mp;
        return word1.length()+word2.length()-2*recurse(word1,word2,word1.length()-1,word2.length()-1,mp);
    }
};