class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        for(int i = 22; i >= 0; i--){
            if((num&(1<<i))){
                res+=(i);
                break;
            }
        }
        cout << res;
        return res + __builtin_popcount(num);
    }
};