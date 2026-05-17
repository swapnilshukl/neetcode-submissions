class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int currSum = 0, count = 0;

        for(int x : nums){
            currSum += x;
        
        if(mp.find(currSum-k)!=mp.end()) count += mp[currSum-k];
        mp[currSum]++;
        }
        return count;
    }
};