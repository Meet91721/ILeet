class Solution {
public:
    
    int timeTaken(vector<int> &weights, int capacity){
        int days = 0;
        int c = 0;
        for(int i = 0; i < weights.size(); i++){
            if(c+weights[i] >capacity){
                days++;
                c=weights[i];
            }
            else{
                c+=weights[i];
            }
        }
        if(c)
            days++;
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int i = *max_element(weights.begin(),weights.end());
        int j = accumulate(weights.begin(),weights.end(),0);
        while(i < j){
            int mid = (i+j)/2;
            int d = timeTaken(weights,mid);
            if(d > days){
                i = mid+1;
            }
            else{
                j = mid;
            }
        }
        return i;
    }
};