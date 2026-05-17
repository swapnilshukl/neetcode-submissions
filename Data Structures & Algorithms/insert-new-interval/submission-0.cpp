class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        bool inserted = false;

        for(auto &interval : intervals){
            int s = interval[0];
            int e = interval[1];
            if(e < newInterval[0]){
                res.push_back({s,e});
            }
            else if(s > newInterval[1]){
                if(!inserted){
                res.push_back(newInterval);
                inserted = true;
                }
                res.push_back({s,e});
            }
            else{
                newInterval[0] = min(newInterval[0], s);
                newInterval[1] = max(newInterval[1], e);
            }
        }
        if(!inserted) res.push_back(newInterval);
        return res;

    }
};
