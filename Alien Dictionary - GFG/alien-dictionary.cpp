//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dictionary[], int N, int k) {
        //code here
        vector<int>available(26);
    vector<int>inDegree(26);
    vector<vector<int>>g(26);

    
    for(int i = 1; i < N; i++){
        int len = min(dictionary[i].length(), dictionary[i-1].length());
        int j = 0;
        while(j < len && dictionary[i][j]==dictionary[i-1][j]){
            available[dictionary[i-1][j]-'a']=1;
            available[dictionary[i][j]-'a']=1;
            j++;
        }
        if(j < len){
            inDegree[dictionary[i][j] - 'a']++;
            g[dictionary[i-1][j]-'a'].push_back(dictionary[i][j]-'a');
        }
        while(j < len){
            available[dictionary[i][j] - 'a']=1;
            available[dictionary[i-1][j] - 'a']=1;
            j++;
        }
        while(j < dictionary[i].length()){
            available[dictionary[i][j] - 'a']=1;
            j++;
        }
        while(j < dictionary[i-1].length()){
            available[dictionary[i-1][j] - 'a']=1;
            j++;
        }
    }
    queue<int>q;
    for(int i = 0; i < 26; i++){
        if((available[i]) && (0 == inDegree[i])){
            q.push(i);
        }
    }
    
    string s;
    while(q.size()){
        int node = q.front();
        q.pop();
        char c = node + 'a';
        s += c;
        for(auto child: g[node]){
            inDegree[child]--;
            if(inDegree[child] == 0){
                q.push(child);
            }
        }
    }
    return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends