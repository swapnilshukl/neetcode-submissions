class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int &currArea){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) return;

        currArea++;
        grid[r][c] =0;

        dfs(grid, r+1, c, currArea);
        dfs(grid, r-1, c, currArea);
        dfs(grid, r, c+1, currArea);
        dfs(grid, r, c-1, currArea);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;
        int currArea = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1){
                    dfs(grid, i, j, currArea);
                    maxArea = max(maxArea, currArea);
                    currArea = 0;
                }
            }
        }
        return maxArea;
    }
};
