class Solution {
public:
    
    bool funcc(int i, int s1, int s2, int s3, int s4, vector<int>&v){
        if(s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0)
            return true;
        if(s1<0 || s2 <0 || s3<0 || s4<0)
            return false;
        return funcc(i-1,s1-v[i],s2,s3,s4,v) || funcc(i-1,s1,s2-v[i],s3,s4,v) || funcc(i-1,s1,s2,s3-v[i],s4,v) || funcc(i-1,s1,s2,s3,s4-v[i],v);
    }
    
    bool makesquare(vector<int>& v) {
        if(v.size() <4 || accumulate(v.begin(),v.end(),0)%4){
            return false;
        }
        int length = accumulate(v.begin(),v.end(),0)/4;
        sort(v.begin(),v.end());
        return funcc(v.size()-1,length,length,length,length,v);
    }
};