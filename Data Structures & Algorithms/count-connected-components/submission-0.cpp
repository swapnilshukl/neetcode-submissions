class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool>vis(n, false);
        int components = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                components++;
                queue<int>q;
                q.push(i);
                vis[i] = true;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto it: adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=true;
                        }
                    }
                }
            }
        }
        return components;
    }
};
