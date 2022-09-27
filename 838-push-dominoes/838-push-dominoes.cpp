class Solution {
public:
    string pushDominoes(string dominoes) {
        bool left = 0;
        for(int i = 0; i < dominoes.size(); i++){
            // cout << "ASD";
            if(dominoes[i] == '.')
                left = true;
            else if(dominoes[i] == 'L'){
                int t = i-1;
                while(t >= 0 && dominoes[t]=='.')
                    dominoes[t--]='L';
                left = false;
            }
            else {
                left = false;
                int t = ++i;
                while(t < dominoes.size() && dominoes[t] != 'L'){
                    if(dominoes[t] == 'R'){
                        for(; i <= t; i++)
                            dominoes[i] = 'R';
                    }
                    t++;
                }
                // cout << dominoes[i] ;
                
                int temp = t;
                t--;
                // cout << i << " " << t << '\n';
                if(temp == dominoes.size()){
                    for(; i < dominoes.size(); i++)
                        dominoes[i] = 'R';
                }
                else{
                    while(i < t){
                        // cout << "HERE: " << i << " " << t << '\n';
                        dominoes[i++] = 'R';
                        dominoes[t--] = 'L';
                        // cout << dominoes << '\n';
                    }
                }
                i = temp;
            }
        }
        return dominoes;
    }
};