class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int head = 0, tail = size - 1;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            int num = nums[mid];
            
            if(size - mid > num){
                head = mid + 1;
            }
            else if(size - mid < num){
                tail = mid - 1;
            }
            else{
                if(mid != 0 && num == nums[mid - 1]){
                    tail = mid - 1;
                    continue;
                }
                return num;
            }
        }
        // cout << head << "  " << tail << '\n';
        if(head < size - 1){
            if(size - head - 1< nums[head + 1] && size - head - 1 > nums[head])
                return size - head - 1;
            
            if(head)
                if(size - head > nums[head - 1] && size - head < nums[head])
                    return size - head;
            
        }
        if(head == 0)
            if(nums[head] > size)
                return size;
        return -1;
    }
    // int specialArray(vector<int>& nums){
    //     sort(nums.begin(), nums.end());
    //     for(int i = 0; i < nums.size(); i++){
    //         if(nums[i] > nums.size() - 1){
    //             return -1;
    //         }
    //     }
    // }
};

// 7 7 8 8 8 8 8 8 8 8
// 1 2 3 4 5 6