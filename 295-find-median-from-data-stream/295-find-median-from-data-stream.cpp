class MedianFinder {
public:
    
    multiset<int, greater<int>> small, large;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.insert(num);
        large.insert(-1*(*small.begin()));
        small.erase(small.begin());
        if(small.size()<large.size()){
            small.insert(-1*(*large.begin()));
            large.erase(large.begin());
        }
    }
    
    double findMedian() {
        if(small.size() == large.size())
            return (((*small.begin())-(*large.begin()))/2.0);
        return *small.begin();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */