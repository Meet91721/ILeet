class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for(int i = 0; i < flowerbed.size() && n!=0; i++){
            // cout << i << '\n';
            if(flowerbed[i] == 1){
                i++;
                continue;
            }
            if(i < flowerbed.size()-1){
                if(flowerbed[i+1] == 1)
                    continue;
            }
            n--;
            i++;
            continue;
        }
        if(n)
            return false;
        return true;
    }
};