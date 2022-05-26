// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int head = 1, tail = n;
        unsigned int mid;
        while(head <= tail){
            mid = (head + tail) / 2;
            if(isBadVersion(mid)){
                tail = mid-1;
            }
            else{
                head = mid+1;
            }
        }
        if(isBadVersion(mid)){
            return mid;
        }
        return mid+1;
    }
};