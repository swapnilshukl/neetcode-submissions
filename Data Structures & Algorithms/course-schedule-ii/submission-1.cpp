class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses,0);

        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }

        queue<int>q;

        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};
