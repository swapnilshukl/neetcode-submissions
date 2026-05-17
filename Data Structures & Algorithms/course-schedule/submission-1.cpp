class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses,0);

        for(auto &p: prerequisites){
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }

        queue<int>q;

        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0)q.push(i);
        }
        int count = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            count++;

            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        return count == numCourses ? true:false;
    }
};
