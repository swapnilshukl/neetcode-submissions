class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto i : nums){
            mp[i]++;
        }

        vector<int>res;
        vector<vector<int>>buckets(n+1);
        for(auto const&[ele, freq] : mp){
            buckets[freq].push_back(ele);
        }

        for(int i=n; i>=0 && res.size()<k; i--){
            if(!buckets.empty()){
                for(int element : buckets[i]){
                    res.push_back(element);
                    if(res.size()==k) break;
                }
            }
        }
        return res;
    }
};
