class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int maxLeft = height[0];
        int maxRight = height[n - 1];
        int left = 1;
        int right = n - 2;
        int waterCount = 0;

        while (left <= right){
            if (maxLeft <= maxRight){
                if (height[left] < maxLeft){
                    waterCount += maxLeft - height[left];
                }
                else{
                    maxLeft = height[left];
                }

                left++;
            }
            else{
                if (height[right] < maxRight){
                    waterCount += maxRight - height[right];
                }
                else{
                    maxRight = height[right];
                }

                right--;
            }
        }

        return waterCount;
    }
};