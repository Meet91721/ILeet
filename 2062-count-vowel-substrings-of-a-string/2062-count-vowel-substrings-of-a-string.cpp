class Solution {
public:
    int countVowelSubstrings(string word) {
        int res = 0;
        int last = INT_MAX;
        int a = INT_MAX, e = INT_MAX,  ii = INT_MAX, o = INT_MAX, u= INT_MAX;
        for(int i = 0; i < word.length(); i++){
            if(word[i] == 'a'){
                if(last==INT_MAX){
                    last = i;
                }
                a = i;
            }
            else if(word[i] == 'e'){
                e=i;
                if(last == INT_MAX)
                    last = i;
            }
            else if(word[i] == 'i'){
                if(last == INT_MAX)
                    last = i;
                ii=i;
            }
            else if(word[i] == 'o'){
                if(last == INT_MAX)
                    last = i;
                o=i;
            }
            else if(word[i] == 'u'){
                if(last==INT_MAX)
                    last=i;
                u=i;
            }
            else{
                last=INT_MAX;
                a = INT_MAX, e = INT_MAX,  ii = INT_MAX, o = INT_MAX, u= INT_MAX;
            }
            if(max({a,e,ii,o,u})!=INT_MAX){
                res+=min({a,e,ii,o,u})-last+1;
            }
        }
        return res;
    }
};