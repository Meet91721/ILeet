// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxNumbers(int n, int k, int a[]){
        // code here
        int sum = 0;
        sort(a,a+n);
        int cnt = 0;
        int index = 0;
        for(int i = 1; sum<k; i++){
            if(a[index]==i){
                while(a[index]==i)
                    index++;
                continue;
            }
            if(sum+i<k){
                cnt++;
                sum+=i;
            }
            else
            break;
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[n];
        for(int i = 0; i < n; i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.maxNumbers(n, k, a)<<"\n";
    }
    return 0;
}  // } Driver Code Ends