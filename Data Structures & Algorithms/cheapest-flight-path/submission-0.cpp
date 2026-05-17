class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int>dist(n, INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int u = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;
            for(auto it : adj[u]){
                int v = it.first;
                int dis = it.second;
                if(cost + dis < dist[v] && stops <=k){
                    dist[v] = dis + cost;
                    q.push({stops+1,{v, dist[v]}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1: dist[dst];
    }
};
