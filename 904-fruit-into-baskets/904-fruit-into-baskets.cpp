class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int fruitA = 0, fruitB = 0;
        int a = -1, b = -1;
        int res = 0;
        for(int i = 0; i < fruits.size(); i++){
            if(fruits[i] == a){
                fruitA++;
                res = max(fruitA+fruitB,res);
                continue;
            }
            if(fruits[i] == b){
                fruitB++;
                res = max(fruitA+fruitB,res);
                continue;
            }
            
            if(a == -1)
            {
                a = fruits[i];
                fruitA = 1;
                res = max(fruitA+fruitB,res);
                continue;
            }
            if(b == -1){
                b = fruits[i];
                fruitB = 1;
                res = max(fruitA+fruitB,res);
                continue;
            }
            if(fruits[i-1] == a){
                fruitA = fruitB = 0;
                int temp = i-1;
                while(fruits[temp] == a){
                    fruitA++;
                    temp--;
                }
                fruitB = 1;
                b = fruits[i];
                res = max(fruitA+fruitB,res);
                continue;
            }
            fruitB = fruitA = 0;
            int temp = i-1;
            a = b;
            while(fruits[temp] == a){
                temp--;
                fruitA++;
            }
            b = fruits[i];
            fruitB=1;
            res = max(fruitA+fruitB,res);
            continue;
        }
        return res;
    }
};