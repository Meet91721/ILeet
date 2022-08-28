class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int i = nums.size()-1;
        stack<int>stk;
        vector<int>res(nums.size(),-1);
        while(i>=-1*(int)nums.size()){
            int index = (i+2*nums.size())%nums.size();
            
            while(stk.size()>0 && stk.top()<=nums[index]){
                stk.pop();
            }
            if(stk.size()){
                res[index] = stk.top();
            }
            stk.push(nums[index]);
            i--;
        }
        return res;
    }
};