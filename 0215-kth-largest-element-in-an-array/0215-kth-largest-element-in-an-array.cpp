class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k) return INT_MIN;

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int x : nums){
            minHeap.push(x);

            if (minHeap.size() > k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};