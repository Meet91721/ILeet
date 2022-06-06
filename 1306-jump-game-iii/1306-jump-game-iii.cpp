class Solution {
public:
    
    constexpr static int N = 100100;
    unordered_map<int,bool> mp;
    bool vis[N];
    
    bool recurse(vector<int>& arr, int posn){
        
        if(posn >= arr.size() || posn < 0)
            return false;
        
        if(mp.find(posn) != mp.end())
            return mp[posn];
        
        if(arr[posn] == 0)
            return true;
        
        vis[posn] = true;
        
        bool temp = false;
        
        if(posn - arr[posn] >= 0 && vis[posn - arr[posn]] == 0){
            temp = recurse(arr, posn - arr[posn]);
        }
        
        if(posn + arr[posn] < arr.size() && vis[posn + arr[posn]] == 0){
            temp = temp | recurse(arr, posn + arr[posn]);
        }
        
        mp[posn] = temp;
        return temp;
    }
    
    bool canReach(vector<int>& arr, int start) {
        return recurse(arr, start);
    }
};

/*
    3 0 1 2 1 2
*/