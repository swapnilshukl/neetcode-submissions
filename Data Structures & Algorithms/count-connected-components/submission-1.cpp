class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<bool>&vis, int node){
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(adj, vis, it);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        int components = 0;
        vector<bool>vis(n, false);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                components++;
                dfs(adj, vis, i);
            }
        }
        return components;
    }
};
