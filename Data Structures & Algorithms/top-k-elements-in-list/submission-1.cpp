class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>res;
        for(int num : nums){
            mp[num]++;
        }

        vector<vector<int>>buckets(n+1);
        for(auto const& [element, frequency]: mp){
            buckets[frequency].push_back(element);
        }

        for(int i=n; i>=0 && res.size() < k; i--){
            if(!buckets.empty()){
                for(int element : buckets[i]){
                    res.push_back(element);
                    if(res.size() == k) break;
                }
            }
        }
        return res;
    }
};
