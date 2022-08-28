class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>left,right;
        vector<int>l(heights.size(),0),r(heights.size(),0);
        for(int i = 0; i < heights.size(); i++){
            while(left.size()>0 && left.top().first>=heights[i])
                left.pop();
            if(left.size())
                l[i]=left.top().second+1;
            else
                l[i]=0;
            left.push({heights[i],i});
        }
        for(int i = heights.size()-1; i>= 0; i--){
            while(right.size()>0 && right.top().first>=heights[i])
                right.pop();
            if(right.size())
                r[i]=right.top().second-1;
            else
                r[i]=heights.size()-1;
            right.push({heights[i],i});
        }
        // for(int i = 0; i < heights.size(); i++)
        //     cout << l[i] << " ";
        // cout << '\n';
        // for(int i = 0; i < heights.size(); i++)
        //     cout << r[i] << " ";
        // cout << '\n';
        int res=0;
        for(int i = 0; i < heights.size(); i++){
            res = max(res,(r[i]-l[i]+1)*heights[i]);
        }
        return res;
        return -1;
    }
};