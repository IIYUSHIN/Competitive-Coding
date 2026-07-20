class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (st.top() != -1 &&
                   heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = i - st.top() - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }
        while (st.top() != -1) {
            int h = heights[st.top()];
            st.pop();
            int w = heights.size() - st.top() - 1;
            ans = max(ans, h * w);
        }
        return ans;
    }
};