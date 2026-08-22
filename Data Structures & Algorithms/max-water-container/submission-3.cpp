class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int maxiArea = INT_MIN;
        int maxLeft = -1;
        int maxRight = -1;

        while(l < r){
            maxLeft = max(maxLeft, heights[l]);
            maxRight = max(maxRight, heights[r]);
            int area = min(maxRight, maxLeft)*(r-l);

            maxiArea = max(maxiArea,area);

            if(maxLeft > maxRight) r--;
            else l++;
        }
        return maxiArea;
    }
};
