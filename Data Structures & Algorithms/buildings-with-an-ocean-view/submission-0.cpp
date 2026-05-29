class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int>ans;
        stack<int>st;
        int n = heights.size();

        for(int i=n-1; i>=0; i--){
            int curr = heights[i];
            if(st.empty() || curr > heights[st.top()]){
                ans.push_back(i);
                st.push(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};