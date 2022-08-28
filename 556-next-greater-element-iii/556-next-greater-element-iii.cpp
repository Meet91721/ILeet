class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>hsh(10,0);
        string num = to_string(n);
        int i = num.length()-1;
        for(; i >= 0; i--){
            for(int j = 1+num[i]-'0'; j <= 9; j++){
                if(hsh[j]){
                    hsh[num[i]-'0']++;
                    num[i] = j+'0';
                    hsh[j]--;
                    i++;
                    for(int digit = 0; digit < 10; digit++){
                        int count = hsh[digit];
                        while(count--){
                            num[i] = digit+'0';
                            i++;
                        }
                    }
                    try{
                        return stoi(num);
                    }
                    catch (...){
                        return -1;
                    }
                }
            }
            hsh[num[i]-'0']++;
        }
        return -1;
    }
};