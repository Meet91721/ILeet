class Solution {
    
    int no_of_operations(int n){
        int op = 0;
        op+=n/60;
        n-=op*60;
        
        int temp = n/15;
        op+=temp;
        n-=15*temp;
        temp = n/5;
        op+=temp;
        n-=5*temp;
        op+=n;
        return op;
    }
    
public:
    int convertTime(string current, string correct) {
        int hr = stoi(correct.substr(0,2)) - stoi(current.substr(0,2));
        int min = stoi(correct.substr(3,2)) - stoi(current.substr(3,2));
        
        if(min>=0){
            min+=hr*60;
            // cout << min << '\n';
            return no_of_operations(min);
        }
        // cout << min << '\n';
        min = 60+min + 60*(hr-1);
        // cout << min << '\n';
        return no_of_operations(min);
    }
};