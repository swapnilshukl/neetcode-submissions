class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i : nums){
            mp[i]++;
        }

        vector<int>ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(auto i : mp){
            pq.push({i.second, i.first});

            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
