class Solution {
public:
    
    map<int, int> mp;
    
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
        
        int t1, t2;
        if(mp.find(n - 1) == mp.end())
        {
            t1 = funcc(n - 1);
            mp[n - 1] = t1;
        }
        else
            t1 = mp[n - 1];
        if(mp.find(n - 2) == mp.end()){
            t2 = funcc(n - 2);
            mp[n - 2] = t2;
        }
        else
            t2 = mp[n - 2];
        return t1 + t2;
        
    }
    
    int climbStairs(int n) {
        return funcc(n);
    }
};