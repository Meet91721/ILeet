class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int head = 0, tail = nums.size() - 1;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            if(nums[mid] <= 0){
                if(mid != nums.size() - 1 && nums[mid + 1] < 0){
                    // cout << "HELLO" << tail << " " << head << '\n';
                    head = mid + 1;
                    continue;
                }
                head = mid;
                tail = mid + 1;
                break;
            }
            else{
                tail = mid - 1;
            }
        }
        // cout << head << " " << tail << '\n';
        if(tail == -1){
            tail++;
            head--;
        }
        if(head == nums.size()){
            head--;
            tail++;
        }
        
        vector<int>res;
        while(head != -1 && tail != nums.size()){
            if(abs(nums[head]) < abs(nums[tail])){
                res.push_back(nums[head] * nums[head]);
                head--;
            }
            else{
                res.push_back(nums[tail] * nums[tail]);
                tail++;
            }
        }
        while(head!=-1){
            res.push_back(nums[head] * nums[head]);
            head--;
        }
        while(tail != nums.size()){
            res.push_back(nums[tail] * nums[tail]);
            tail++;
        }
        return res;
    }
};