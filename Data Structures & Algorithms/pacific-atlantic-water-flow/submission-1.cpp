class Solution {
public:
    int m, n;
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>&vis){
        vis[i][j] = true;

        vector<pair<int,int>>dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for(auto d : dir){
            int ni = i + d.first;
            int nj = j + d.second;

            if(ni >=0 && ni < m && nj >=0 && nj < n && !vis[ni][nj] && heights[ni][nj]>=heights[i][j]){
                dfs(heights, ni, nj, vis);
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>>pacific(m, vector<bool>(n,false));
        vector<vector<bool>>atlantic(m, vector<bool>(n,false));

        for(int i=0; i<m; i++){
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n-1, atlantic);
        }

        for(int j=0; j<n; j++){
            dfs(heights, 0, j, pacific);
            dfs(heights, m-1, j, atlantic);
        }

        vector<vector<int>>res;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
