class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>plates;
        for(int i = 0; i < (int)s.size(); i++)
            if(s[i] == '|')
                plates.push_back(i);
        vector<int>res;
        for(int i = 0; i < queries.size(); i++){
            auto l = lower_bound(plates.begin(),plates.end(),queries[i][0]);
            if(l == plates.end() || *l > queries[i][1]){
                res.push_back(0);
                continue;
            }
            auto r = lower_bound(l,plates.end(),queries[i][1]);
            if(r == plates.end() || *r!=queries[i][1])
                advance(r,-1);
            if(((*r)-(*l))-distance(l,r)>0)
                res.push_back(((*r)-(*l))-distance(l,r));
            else 
                res.push_back(0);
        }
        return res;
    }
};