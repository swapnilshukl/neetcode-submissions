class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<double>st;
        vector<pair<int,double>>time;

        for(int i=0; i<n; i++){
            double t = (double)(target - position[i])/speed[i];
            time.push_back({position[i], t});
        }

        sort(time.begin(), time.end());

        for(int i=n-1; i>=0; i--){
            double currTime = time[i].second;

            if(st.empty() || currTime > st.top()){
                st.push(currTime);
            }
        }
        return st.size();
    }
};
