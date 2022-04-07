class Solution {
public:
    
    map<int, int>mp;
    
    int funcc(int i, int n, vector<int>& arr){
        if(i == n - 1){
            mp[i] = 0;
            return 0;
        }
        if(i == n - 2){
            mp[i] = arr[n-1];
            return arr[n - 1];
        }
        if(i == n - 3){
            mp[i] = arr[n - 2];
            return arr[n - 2];
        }
        
        if(mp.find(i) == mp.end()){
            int t1 = arr[i+1]+funcc(i+2,n,arr);
            int t2 = 0;
            if(i<n-3){
                t2 = arr[i+1]+arr[i+2]+funcc(i+3,n,arr);
            }
            mp[i] = min(t1,t2);
            return min(t1,t2);
        }
        return mp[i];
        
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        return min(funcc(0,cost.size(),cost), funcc(-1, cost.size(), cost));
    }
};