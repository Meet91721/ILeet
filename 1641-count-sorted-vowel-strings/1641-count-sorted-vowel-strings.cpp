class Solution {
public:
    
    int recurse(char word, int n, int index){
        if(index == n){
            if(word=='a')
                return 5;
            if(word=='b')
                return 4;
            if(word=='c')
                return 3;
            if(word=='d')
                return 2;
            return 1;
        }
        int cnt = 0;
        for(int i = word-'a'; i < 5; i++){
            cnt+=recurse(i+'a', n, index+1);
        }
        return cnt;
    }
    
    int countVowelStrings(int n) {
        int cnt = 0;
        // for(int i = 0; i < 5; i++)
            cnt+=recurse('a',n,1);
        return cnt;
    }
};