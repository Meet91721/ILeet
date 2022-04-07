class Solution {
public:
    
    int arr[40];
    
    int funcc(int n){
        arr[0]=0;
        arr[1]=1;
        arr[2]=1;
        for(int i = 0; i < n - 2; i++){
            arr[i+3]+=arr[i];
            arr[i+3]+=arr[i+1];
            arr[i+3]+=arr[i+2];
        }
        return arr[n];
    }
    
    int tribonacci(int n) {
        return funcc(n);
    }
};