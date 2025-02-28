class MedianFinder {
public:
    priority_queue<int> maxPq;
    priority_queue<int,vector<int>,greater<int>> minPq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxPq.size() == 0 || maxPq.top() > num) {
            maxPq.push(num);
        } else {
            minPq.push(num);
        }

        if (maxPq.size() > minPq.size() + 1) {
            int temp = maxPq.top();
            maxPq.pop();
            minPq.push(temp);
        } else if ( minPq.size() > maxPq.size() + 1){
            int temp = minPq.top();
            minPq.pop();
            maxPq.push(temp);
        }
    }
    
    double findMedian() {
        double ans;
        if (maxPq.size() == minPq.size()){
            return (double)(maxPq.top() + minPq.top())/2;
        } else if (maxPq.size() > minPq.size()) {
            return (double)(maxPq.top());
        } else {
            return (double)(minPq.top());
        }

        return 0;  
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */