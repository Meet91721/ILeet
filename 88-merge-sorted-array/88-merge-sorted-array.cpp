class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        bool flipped = false;
        vector<int>nums(n+m);
        int i = 0, j = 0;
        int x = 0;
        for(; i < m && j < n; x++){
            // cout << x << '\n';
            if(nums1[i] < nums2[j]){
                nums[x] = nums1[i];
                i++;
            }else{
                nums[x] = nums2[j];
                j++;
            }
        }
        while(i < m){
            nums[x] = nums1[i];
            x++;
            i++;
        }
        while(j < n){
            nums[x] = nums2[j];
            j++;
            x++;
        }
        nums1 = nums;
    }
};