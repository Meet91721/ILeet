class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        vector<int>hash(256);
        int l = 0, r = 0;
        int mx = 1;
        int ind = s[l];
        hash[ind]=1;
        for(int i = 1; i < s.length(); i++){
            r++;
            ind = s[r];
            if(hash[ind]){
                while (l != r && s[l]!=s[r]){
                    int t = s[l];
                    hash[t]=0;
                    l++;
                }
                l++;
                hash[ind]=1;
                mx = max(mx, r - l + 1);
                continue;
            }
            hash[ind]=1;
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};
// abcabcbb
// l = 0, r = 1
// l = 0, r = 2  mx = 3
// l = , r = 3