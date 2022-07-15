class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int area = 0;
        // TC -> hcuts*Vcuts
        horizontalCuts.insert(horizontalCuts.begin(),0);
        verticalCuts.insert(verticalCuts.begin(),0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int mod = 1000000007;
        int hMax = 0;
        for(int i = 0; i < horizontalCuts.size()-1; i++){
            hMax = max(hMax,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        int vMax = 0;
        for(int i = 0; i < verticalCuts.size()-1; i++){
            vMax = max(vMax,verticalCuts[i+1]-verticalCuts[i]);
        }
        
        return (((1LL*hMax)%mod)*((vMax*1LL)%mod))%mod;
    }
};