class Solution {
public:
    constexpr static int N = 1100;
    int hash[N][26];
    int maxProduct(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                hash[i][words[i][j] - 'a']=1;
            }
        }
        int res = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                bool check = true;
                for(int k = 0; k < 26; k++){
                    if(hash[i][k] + hash[j][k] > 1){
                        check = false;
                        break;
                    }
                }
                if(check){
                    int temp = words[i].size() * words[j].size();
                    if(temp > res)
                        res = temp;
                }
            }
        }
        return res;
    }
};