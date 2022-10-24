class Solution {
public:
    
    double median(vector<int>& n1, vector<int>&n2){
        int len1 = n1.size(), len2 = n2.size();
        int l = 0, r = len1;
        while(l <= r){
            int mid1 = l + (r-l)/2;
            int mid2 = (len1+len2+1)/2-mid1;
            int maxl1 = (mid1==0)?INT_MIN:n1[mid1-1];
            int maxl2 = (mid2==0)?INT_MIN:n2[mid2-1];
            int minr1 = (mid1==len1)?INT_MAX:n1[mid1];
            int minr2 = (mid2==len2)?INT_MAX:n2[mid2];
            if(maxl1<=minr2 && maxl2<=minr1){
                if((len1+len2)%2){
                    return (double)max(maxl1,maxl2);
                }
                return (double)(max(maxl1,maxl2)+min(minr1,minr2))/2.0;
            }
            if(maxl1>minr2)
                r = mid1-1;
            else
                l = mid1+1;
        }
        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() <= nums2.size())
            return median(nums1,nums2);
        return median(nums2,nums1);
    }
};