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
        cout << head << "  " << tail << '\n';
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
};

// 0 3 6 7 7
// mid = 2, num = 6
// mid = 0, num = 0


// 0 0 1 4 6 9
// mid = 2, num = 1
// mid = 4, num = 6
// mid

// 0 0
// mid = 0, num = 0
// mid = 1, num = 0

// 3 5
// mid = 0, num = 3

// 0 0 3 4 4
// mid = 2, num = 3
// mid = 0, num = 0
