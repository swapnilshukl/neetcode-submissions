class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<int>st;

        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || heights[i] < heights[st.top()])){
                int height = heights[st.top()];
                st.pop();

                int leftBoundary;
                if(st.empty()){
                    leftBoundary = -1;
                }else{
                    leftBoundary = st.top();
                }

                int rightBoundary = i;
                int width = rightBoundary - leftBoundary - 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            st.push(i);

        }
        return maxArea;
    }
};
