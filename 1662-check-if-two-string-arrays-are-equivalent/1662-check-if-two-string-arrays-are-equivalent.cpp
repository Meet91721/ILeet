class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int i = 0, j = 0;
        int v1 = 0, v2 = 0;
        while(true){
            if(v1==w1.size() && v2==w2.size())
                return true;
            if(v1==w1.size() || v2==w2.size())
                return false;
            
            for(; i<w1[v1].size() && j<w2[v2].size(); i++,j++){
                if(w1[v1][i]!=w2[v2][j])
                    return false;
            }
            if(i==w1[v1].size()){
                i=0;
                v1++;
            }
            if(j==w2[v2].size()){
                j=0;
                v2++;
            }
        }
        return false;
    }
};