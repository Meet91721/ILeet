class Solution {
public:
    
    unordered_map<int,int>mp;
    
    int recurse(vector<int>&coins, int amount){
        if(amount == 0){
            return 0;
        }
        
        if(mp.find(amount) != mp.end()){
            return mp[amount];
        }
        long long int cnt = INT_MAX;
        for(auto &coin: coins){
            if(amount - coin >= 0){
                cnt = min(cnt,1+1LL*recurse(coins, amount-coin));
            }
        }
        mp[amount] = cnt;
        return cnt;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        if(int i = recurse(coins, amount); i == INT_MAX)
            return -1;
        else{
            return i;
        }
    }
};