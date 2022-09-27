class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(),arr.end(),x);
        int r = distance(arr.begin(),it);
        int l = r-1;
        vector<int>res;
        while(k--)
            if(r==arr.size()){
                res.push_back(arr[l--]);
            }
            else if(l < 0){
                res.push_back(arr[r++]);
            }
            else{
                res.push_back(abs(arr[r]-x)<abs(arr[l]-x)?arr[r++]:arr[l--]);
            }
        sort(res.begin(),res.end());
        return res;
    }
};