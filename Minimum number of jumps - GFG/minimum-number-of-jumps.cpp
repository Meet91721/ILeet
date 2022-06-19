// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int buffer = 1;
        int temp = 1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            buffer--;
            temp--;
            buffer = max(buffer,arr[i]);
            // cout << buffer << " " << temp << '\n';
            if(temp<=0){
                if(i!=n-1)
                    cnt++;
                temp=max(buffer,arr[i]);
            }
            if(temp==0&&i!=n-1)
                return -1;
            // cout << buffer << " " << temp << '\n';
            // else{
            //     temp--;
            // }
            // buffer = max(buffer,arr[i]);
        }
        return cnt;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends