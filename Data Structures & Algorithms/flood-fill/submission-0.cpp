class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ocolor = image[sr][sc];
       
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>grid = image;
         if (ocolor == color) return image; 
        grid[sr][sc] = color;

        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};


        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto[x,y] = q.front();
                q.pop();

                for(auto d : dir){
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==ocolor){
                        grid[nx][ny] = color;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return grid;
    }
};