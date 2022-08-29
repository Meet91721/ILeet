class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        int i = nums.size()-1;
        stack<char>stk;
        multiset<char>ms;
        
        for(;i>=0;i--){
            while(stk.size()>0 && stk.top()<=nums[i]){
                ms.insert(stk.top());
                stk.pop();
            }
            if(stk.size()){
                ms.insert(nums[i]);
                char here = stk.top();
                for(auto it: ms){
                    if(it>nums[i])
                        here = min(here,it);
                }
                while(stk.size()){
                    ms.insert(stk.top());
                    stk.pop();
                }
                auto it = ms.find(here);
                ms.erase(it);
                nums[i] = here;
                i++;
                for(auto it: ms){
                    nums[i++] = it;
                }
                try{
                    return stoi(nums);
                }
                catch(...){
                    return -1;
                }
            }
            stk.push(nums[i]);
        }
        return -1;
    }
};