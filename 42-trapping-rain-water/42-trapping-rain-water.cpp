class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n-1);
        vector<int>right(n);
        for(int i = 1; i < height.size(); i++){
            left[i-1]=height[i];
            right[i]=height[i-1];
        }
        left.push_back(0);
        for(int i = n-3; i>= 0; i--){
            left[i] = max(left[i],left[i+1]);
        }
        for(int i = 1; i < n; i++){
            right[i] = max(right[i],right[i-1]);
        }
        for(int i = 0; i < n; i++)
            left[i] = min(left[i],right[i]);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans+=max(0,left[i]-height[i]);
        return ans;
    }
};