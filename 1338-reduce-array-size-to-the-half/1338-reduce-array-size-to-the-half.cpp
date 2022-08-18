class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>mp;
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]]++;
        multiset<int,greater<int>>ms;
        for(auto it: mp){
            ms.insert(it.second);
        }
        int sum = 0;
        auto it = ms.begin();
        while(it!=ms.end()){
            sum+=*it;
            advance(it,1);
            if(sum>=(arr.size()+1)/2)
                return distance(ms.begin(),it);
        }
        return 0;
    }
};