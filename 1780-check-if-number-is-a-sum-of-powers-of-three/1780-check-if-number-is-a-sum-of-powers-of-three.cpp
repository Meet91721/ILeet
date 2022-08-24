class Solution {
public:
    bool checkPowersOfThree(int n) {
        
        vector<int>v;
        v.push_back(1);
        
        for(int i = 1; i < 17; i++)
            v.push_back(pow(3,i));
        
        int last = 100;
        
        while(n){
            auto it = lower_bound(v.begin(),v.end(),n);
            if(*it != n)
                advance(it,-1);
            
            if(distance(v.begin(),it)==last)
                return false;
            last = distance(v.begin(),it);
            n-=(*it);
        }
        return true;
    }
};