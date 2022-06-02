class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int pos = -1;
        for(int i = 0; temp != 0; i++){
            if(temp%10 == 6){
                pos = i;
            }
            temp /= 10;
        }
        if(pos > -1){
            num += 3*pow(10,pos);
        }
        return num;
    }
};