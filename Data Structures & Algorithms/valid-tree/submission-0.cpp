class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        
        vector<vector<int>>adj(n);
    
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int>q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                if(visited.find(it) == visited.end()){
                visited.insert(it);
                q.push(it);
                }
            }
        }
        return (visited.size() == n);
    }
};
