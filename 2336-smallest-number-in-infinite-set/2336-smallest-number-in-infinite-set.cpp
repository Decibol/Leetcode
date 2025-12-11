class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> popped;
    
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1001; ++i){
            minHeap.push(i);
        }    
    }
    
    int popSmallest() {
        if (!minHeap.empty()){
            int top = minHeap.top();
            minHeap.pop();
            popped.insert(top);

            return top;
        }

        return -1;
    }
    
    void addBack(int num) {
        if (popped.count(num)){
            minHeap.push(num);
            popped.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */