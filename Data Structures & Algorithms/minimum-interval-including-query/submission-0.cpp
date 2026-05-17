class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>>q;
        for(int i=0; i<queries.size(); i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(), q.end());
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;

        vector<int>res(queries.size());
        int i = 0;
        int n = intervals.size();

        for(auto &[query, idx] : q){
            while(i < n && intervals[i][0] <= query){
                int start = intervals[i][0];
                int end = intervals[i][1];
                int len = end - start + 1;

                pq.push({len, end});
                i++;
            }

            while(!pq.empty() && pq.top().second < query){
                pq.pop();
            }

            if(pq.empty()){
                res[idx] = -1;
            }else{
                res[idx] = pq.top().first;
            }
        }
        return res;
    }
};
