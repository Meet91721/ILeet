class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>candleLocation;
        for(int i = 0; i < (int)s.size(); i++)
            if(s[i] == '|')
                candleLocation.push_back(i);
        vector<int>res;
        for(int i = 0; i < (int)queries.size(); i++){
            auto first = lower_bound(candleLocation.begin(), candleLocation.end(),queries[i][0]);
            auto last = first == candleLocation.end()? first: prev(upper_bound(first,candleLocation.end(),queries[i][1]));
            res.push_back(first<last?-(*first)+(*last)-distance(first,last):0);
        }
        return res;
    }
};