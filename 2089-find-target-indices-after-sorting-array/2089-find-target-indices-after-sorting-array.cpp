class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int head = 0, tail = nums.size() - 1;
        int *initial_position = &head;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            if(nums[mid] >= target){
                tail = mid - 1;
            }
            else{
                head = mid + 1;
            }
        }
        int from = head;
        head = 0;
        tail = nums.size() - 1;
         while(head <= tail){
            int mid = head + (tail - head) / 2;
            if(nums[mid] > target){
                tail = mid - 1;
            }
            else{
                head = mid + 1;
            }
        }
        vector<int> res(tail - from + 1);
        iota(res.begin(), res.end(), from);
        // cout << from << " " << tail << '\n';
        
        return res;
    }
};