class Solution {
public:
    
    constexpr static int N = 100000;
    bool vis[N];
    map<int,bool> mp;
    
    bool recurse(vector<int>& arr, int node){
        if(node < 0 || node >= arr.size())
            return false;
        if(arr[node] == 0)
            return true;
        
        if(mp.find(node) != mp.end()){
            return  mp[node];
        }
        vis[node] = true;
        bool temp = false;
        if(node - arr[node] >= 0 && vis[node - arr[node]] == false){
            temp = temp | recurse(arr, node - arr[node]);
        }
        if(node + arr[node] < arr.size() && vis[arr[node] + node] == false)
            temp = temp | recurse(arr, node + arr[node]);
        mp[node] = temp;
        return temp;
    }
    
    bool canReach(vector<int>& arr, int start) {
        return recurse(arr, start);
    }
};