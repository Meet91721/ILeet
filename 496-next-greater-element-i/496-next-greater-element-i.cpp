class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stk;
        map<int,int>mp;
        for(int i = nums2.size()-1; i >= 0; i--){
            while(stk.size()>0 && stk.top()<nums2[i])
                stk.pop();
            if(stk.size()){
                mp[nums2[i]]=stk.top();
            }
            else
                mp[nums2[i]]=-1;
            stk.push(nums2[i]);
        }
        vector<int>res;
        for(int i = 0; i < nums1.size(); i++){
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};