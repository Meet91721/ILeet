class Solution {
public:
    
    bool func(int n){
        if(n==1)
            return true;
        if(n%4 || n==0)
            return false;
        return func(n/4);
    }
    
    bool isPowerOfFour(int n) {
        return func(n);
    }
};