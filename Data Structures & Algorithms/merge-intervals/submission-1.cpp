class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;

        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= currEnd){
                currEnd = max(intervals[i][1], currEnd);
            }else{
                ans.push_back({currStart, currEnd});
                currStart = intervals[i][0];
                currEnd = intervals[i][1];
            }
        }
        ans.push_back({currStart, currEnd});
        return ans;
    }
};
