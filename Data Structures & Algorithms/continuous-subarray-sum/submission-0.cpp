class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0) rem += k;

            if(i > 0 && nums[i-1]==0 && nums[i]==0) return true;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>1) return true;
            }else{
                mp[rem] = i;
            }
        }
        return false;
    }
};