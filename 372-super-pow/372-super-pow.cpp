class Solution {
public:
    
    constexpr static int M = 1337;
    
    int superPow(int a, vector<int>& b) {
        int pow = 0;
        for(int i = 0; i < b.size(); i++){
            pow = (pow * 10 + b[i]) % 1140;
        }
        int res = 1;
        while(pow){
            if(pow&1){
                res = (1LL * a * res) % M;
            }
            a = (1LL * a * a ) % M;
            pow >>= 1;
        }
        return res;
    }
};