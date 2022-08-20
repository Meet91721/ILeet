class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size()-1;
        while(i <= j){
            int hgt = min(height[i],height[j]);
            water = max(water,hgt*(j-i));
            while(i<=j && height[i]<=hgt)
                i++;
            while(i<=j && height[j]<=hgt)
                j--;
        }
        return water;
    }
};