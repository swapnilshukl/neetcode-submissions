class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0, high = m*n-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            int nr = mid/n;
            int nc = mid%n;

            if(matrix[nr][nc] == target) return true;
            else if(matrix[nr][nc] > target) high = nr*n + nc - 1;
            else low = nr*n + nc + 1;
        }
        return false;
    }
};
