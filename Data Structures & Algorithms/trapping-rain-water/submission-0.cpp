class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //int maxArea = 0;

        vector<int>left(n),right(n);
        int leftMax = height[0];
        int rightMax = height[n-1];
        left[0] = leftMax;
        right[n-1] = rightMax;
        for(int i=1; i<n; i++){
            if(height[i] > leftMax){
                leftMax = height[i];
            }
            left[i] = leftMax;
        }

        for(int j=n-2; j>=0; j--){
            if(height[j] > rightMax){
                rightMax = height[j];
            }
            right[j] = rightMax;
        }

        int area = 0;
        for(int j=0; j<n; j++){
            area += (min(left[j], right[j]) - height[j]);
        }
        return area;
    }
};
