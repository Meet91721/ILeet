//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int res = 0;
    void func(string s, int n, int m){
        int num = stoi(s);
        if(num > m)
            return;
        // cout << num << '\n';
        if(num>=n){
            // cout << num << '\n';
            res++;
        }
        if(num%10!=0){
            s+='0'+(num%10-1);
            func(s,n,m);
            s.pop_back();
        }
        if(num%10!=9){
            s+='0'+(num%10+1);
            func(s,n,m);
            s.pop_back();
        }
    }

    int steppingNumbers(int n, int m)
    {
        // Code Here
        string s;
        res=0;
        for(int i = 1; i < 10; i++){
            s='0'+i;
            func(s,n,m);
        }
        if(0>=n&&0<=m)
        res++;
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends