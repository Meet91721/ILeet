class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(),s.end());
        int lo = 0, hi = s.size() - 1;
        while(hi>=lo){
            swap(s[lo],s[hi]);
            hi--;
            lo++;
        }
    }
};