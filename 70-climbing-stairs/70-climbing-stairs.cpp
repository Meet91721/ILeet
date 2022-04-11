class Solution {
public:
    
    unordered_map<int, int> mp;
    
    int funcc(int n){
        
        if(n == 2){
            return 2;
        }
        if (n == 1){
            return 1;
        }
        if(n < 1){
            return 0;
        }
        
        if(mp.find(n) == mp.end()){
            mp[n] = funcc(n - 1) + funcc(n - 2);
            return mp[n];
        }
        return mp[n];
        
    }
    
    int climbStairs(int n) {
        return funcc(n);
    }
};