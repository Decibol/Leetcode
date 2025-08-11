class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int left = 0;
        int right = n - 1;

        while (left < right){
            int width = right - left;
            int length = min(height[left], height[right]);
            int water = length * width;
            maxWater = max(maxWater, water); 
            
            if (height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return maxWater;        
    }
};