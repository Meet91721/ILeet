class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(0);
        for(int i = 0; i < nums.size(); i++){
            if(temp.back()==0){
                if(nums[i]==0){
                    continue;
                }
                temp.push_back(nums[i]);
                continue;
            }
            if(temp.back()<0){
                temp.push_back(nums[i]);
                continue;
            }
            if(nums[i]>0){
                temp.back()*=nums[i];
                continue;
            }
            temp.push_back(nums[i]);
        }
        for(int i = 0; i < temp.size(); i++)
            cout << temp[i] << " \n"[i==temp.size()-1];
        // 0 +ve || -ve 0 +ve || -ve
        int res = 0;
        int i = 1;
        while(i < temp.size()){
            int cnt = 0; // stores negative counts
            int mul = 1;
            int t = i;
            while(i < temp.size() && temp[i]!=0){
                mul*=temp[i];
                if(temp[i] < 0)
                    cnt++;
                cout << i << '\n';
                i++;
            }
            if(cnt%2==0){
                res = max(res,mul);
                i++;
                continue;
            }
            if(i == t+1){
                res = max(res,mul);
                i++;
                continue;
            }
            int firstNeg = 1;
            for(; t < i; t++){
                firstNeg*=temp[t];
                if(temp[t]<0)
                    break;
            }
            int lastNeg = 1;
            t = i-1;
            for(; ; t--){
                lastNeg*=temp[t];
                if(temp[t]<0)
                    break;
            }
            mul = max({mul,mul/(firstNeg),mul/(lastNeg)});
            res = max(res,mul);
            i++;
        }
        if(res == 0){
            res = min(res, *max_element(nums.begin(),nums.end()));
        }
        return res;
    }
};