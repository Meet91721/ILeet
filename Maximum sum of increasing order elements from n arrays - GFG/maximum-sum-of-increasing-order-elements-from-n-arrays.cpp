// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends

int findMax(int lessthan, vector<int>&v){
    int mx = INT_MIN;
    for(int i = 0; i < v.size(); i++){
        if(v[i]<lessthan){
            mx = max(mx,v[i]);
        }
    }
    return mx;
}

int maximumSum( int n,int m, vector<vector<int>> &a) {
    int res = 0;
    int previousMax = INT_MAX;
    for(int i = n-1; i >= 0; i--){
        previousMax = findMax(previousMax, a[i]);
        if(previousMax==INT_MIN)
            return 0;
        else
            res+=previousMax;
    }
    return res;
}