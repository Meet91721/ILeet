class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int,greater<int>>b;
        int i = 0;
        for(; i < heights.size() - 1; i++){
            if(heights[i] >= heights[i+1])
                continue;
            int h = abs(heights[i] - heights[i+1]);
            bricks -= h;
            b.insert(h);
            if(bricks < 0){
                bricks+=*b.begin();
                b.erase(b.begin());
                ladders--;
            }
            // if(ladders>0){
            //     ladders--;
            //     if(b.size()>0 && (*b.begin() > h)){
            //         bricks+=*b.begin();
            //         b.erase(b.begin());
            //         bricks-=h;
            //     }
            // }
            // else
            //     break;
            if(ladders < 0)
                break;
        }
        return i;
    }
};