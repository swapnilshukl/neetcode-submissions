class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int s = intervals[0][0];
        int e = intervals[0][1];
        int count = 0;

        for(int i=1; i<n; i++){
            if(intervals[i][0] < e){
                e = min(e, intervals[i][1]);
                count++;
            }else{
                e = intervals[i][1];
            }
        }
        return count;
    }
};
