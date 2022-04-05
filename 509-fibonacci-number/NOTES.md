class Solution {
public:

    //Using memoization(Slower than tabulation)
    
    map<int,long long> mp;
    
    int funcc(int n){
        if(n == 1){
            return 1;
        }
        if (n == 0){
            return 0;
        }
        if(mp.find(n) == mp.end()){
            mp[n] = funcc(n - 1) + funcc(n - 2);
            return mp[n];
        }
        return mp[n];
        
    }
    
    int fib(int n) {
        return funcc(n);
    }
};
