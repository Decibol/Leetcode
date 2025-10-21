class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        int waterCount = 0;

        for (int i = 0; i < height.size(); ++i){
            while (!st.empty() && height[i] > height[st.top()]){
                int top = st.top();
                st.pop();

                if (st.empty()) break;

                int bounded_height = min(height[i], height[st.top()]) - height[top];
                int width = i - st.top() - 1;

                waterCount += bounded_height * width;
            }

            st.push(i);
        }

        return waterCount;
    }
};