class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>res(boxes.size(),0);
        // left to right
        int cnt = 0;
        for(int i = 1; i < boxes.size(); i++){
            if(boxes[i-1]=='1'){
                cnt++;
                res[i]+=res[i-1]+cnt;
            }
            else
                res[i]=res[i-1]+cnt;
        }
        // for(int i = 0; i < boxes.size(); i++)
        //     cout << res[i] << " \n"[i==boxes.size()-1];
        cnt=0;
        vector<int>temp(boxes.size(),0);
        for(int i = boxes.size()-2; i>= 0; i--){
            if(boxes[i+1]=='1'){
                cnt++;
                temp[i]+=cnt+temp[i+1];
            }
            else
                temp[i]=temp[i+1]+cnt;
            res[i]+=temp[i];
        }
        return res;
    }
};