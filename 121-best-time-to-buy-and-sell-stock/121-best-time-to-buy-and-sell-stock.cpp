class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int t_res = 0;
        int maxi = INT_MIN;
        // vextor<int>res;
        // res.push_back(t_res);
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < mini){
                mini = prices[i];
            }
            else{
                if(prices[i] - mini > t_res){
                    t_res = prices[i] - mini;
                }
            }
        }
        return t_res;
    }
};