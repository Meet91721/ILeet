class Solution {
public:
    
    // Using tabulation
    
    int arr[35];
    void funcc(){
        arr[1] = 1;
        for(int i = 0; i < 32; i++){
            arr[i+1]+=arr[i];
            arr[i+2]+=arr[i];
        }
    }
    
    int fib(int n) {
        funcc();
        return arr[n];
    }
};