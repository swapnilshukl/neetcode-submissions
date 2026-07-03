class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = -1;
        int maxRight = -1;
        int n = height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int totalArea = 0;

        for(int i=0; i<n; i++){
            maxLeft = max(maxLeft, height[i]);
            left[i] = maxLeft;
            maxRight = max(maxRight, height[n-i-1]);
            right[n-i-1] = maxRight;
        }

        for(int i=0; i<n; i++){
            totalArea += min(left[i], right[i]) - height[i];
        }
        return totalArea;
    }
};
