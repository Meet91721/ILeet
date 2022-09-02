class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i = 1;
        int j = *max_element(nums.begin(),nums.end())+1;
        while(i<j){
            int mid = (i+j)/2;
            int sum = 0;
            for(int ii = 0; ii < nums.size(); ii++)
                sum+=((nums[ii]+mid-1)/mid);
            if(sum > threshold)
                i = mid+1;
            else
                j = mid;
        }
        return i;
    }
};