class MedianFinder {
private:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        rightMinHeap.push(num);
        leftMaxHeap.push(rightMinHeap.top());
        rightMinHeap.pop();

        if (leftMaxHeap.size() > rightMinHeap.size()){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
    }
    
    double findMedian() {
        if (leftMaxHeap.size() < rightMinHeap.size()) return (double)rightMinHeap.top();
        
        return (double)(leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */