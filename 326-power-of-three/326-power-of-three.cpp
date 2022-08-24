class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n){
            if(n%3){
                if(n==1)
                    return true;
                return false;
            }
            n/=3;
        }
        return false;
    }
};