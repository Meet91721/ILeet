class Solution {
public:
    int reverse(int x) {
        bool isNegative = x<0;
        int temp = 0;
        while(x){
            if(1LL*temp*10>=INT_MAX || 1LL*temp*10<=INT_MIN)
                return 0;
            temp = temp * 10 + x%10;
            x/=10;
        }
        return temp;
    }
};