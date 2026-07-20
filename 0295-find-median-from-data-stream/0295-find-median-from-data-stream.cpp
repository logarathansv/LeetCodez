class MedianFinder {
public:
    priority_queue<int> small; //maxheap
    priority_queue<int, vector<int>, greater<int>> large; // minheap
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num); 
        } else { 
            large.push(num); 
        }
        if(abs((int)small.size() - (int)large.size()) > 1){
            int mxsize = max(small.size(), large.size());
            if(small.size() == mxsize){
                large.push(small.top());
                small.pop();
            } else{
                small.push(large.top());
                large.pop();
            }
        }
    }
    
    double findMedian() {
        if((small.size() + large.size()) % 2 == 0){
            int smele = small.top();
            int laele = large.top();
            return (double)(smele+laele)/2.0;
        } else {
            if(small.size() > large.size()) return small.top();
            else return large.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */