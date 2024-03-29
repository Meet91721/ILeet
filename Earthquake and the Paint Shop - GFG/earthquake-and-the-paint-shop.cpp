//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct alphanumeric {
    string name;
    int count;
} a1;
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int n, vector<string> a) {
        // code here
        map<string,int>mp;
        for(int i= 0; i < n; i++){
            mp[a[i]]++;
        }
        vector<alphanumeric>res;
        
        for(auto it: mp){
            // struct alphanumeric a = (struct alphanumeric *)malloc(sizeof(struct alphanumeric));
            a1.name = it.first;
            a1.count = it.second;
            res.push_back(a1);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u : ans) cout << u.name << " " << u.count << "\n";
    }
}
// } Driver Code Ends