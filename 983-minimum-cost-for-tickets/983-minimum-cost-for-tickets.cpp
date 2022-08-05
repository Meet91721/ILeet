class Solution {
public:
    
    int dp[466][466];
    
    int funcc(int index, vector<int>&days, vector<int>& costs, int day){
        if(index == days.size())
            return 0;
        if(dp[index][day]!=0)
            return dp[index][day];
        if(days[index] <= day)
            return funcc(index+1, days, costs,day);
        int t = costs[0] + funcc(index+1,days,costs,days[index]);
        t = min(t, costs[1] + funcc(index+1,days,costs,days[index]+6));
        t = min(t, costs[2] + funcc(index+1,days,costs,days[index]+29));
        return dp[index][day] = t;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return funcc(0, days, costs, 0);
    }
};