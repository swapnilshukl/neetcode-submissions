class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n+1, INT_MAX);

        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int u = top.second;

            if(d > dist[u]) continue;

            for(auto neighbour : adj[u]){
                int v = neighbour.first;
                int time = neighbour.second;

                if(dist[u]+time < dist[v]){
                    dist[v] = dist[u] + time;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxWait = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1;
            maxWait = max(maxWait, dist[i]);
        }
        return maxWait;
    }
};
