class Solution {
public:
    vector<int>parent;

    int find(int x){
        if(parent[x]!=x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool UnionSet(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return false; //cycle detected

        parent[pu] = pv;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);

        for(int i=1; i<=n; i++)
            parent[i] = i;

        for(auto &e : edges){
            if(!UnionSet(e[0],e[1])){
                return e;
            }
        }
        return {};
    }
};
