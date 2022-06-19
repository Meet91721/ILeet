// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int wineSelling(vector<int>& a){
      //Code here.
    int res=0;
    int curr=0;
    for(int i=0;i<a.size();i++)
    {
        res+=abs(curr);
        curr+=a[i];
    }
    return res;
  }
};



// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        int ans = ob.wineSelling(a);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends