class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>>res;

        int s = intervals[0][0];
        int e = intervals[0][1];

        for(int i=1; i<n; i++){
            if(intervals[i][0] <= e){
                //s = min(s, intervals[i][0]);
                e = max(e, intervals[i][1]);
            }else{
                if(intervals[i][0] > e){
                    res.push_back({s,e});
                    s = intervals[i][0];
                    e = intervals[i][1];
                }
            }

        }
        res.push_back({s,e});
        return res;
    }
};
