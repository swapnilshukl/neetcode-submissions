class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        int zeroCount = 0;
        int ans = INT_MIN;

        for(int r=0; r<n; r++){
            if(nums[r]==0) zeroCount++;

            while(zeroCount > k){
                if(nums[l] == 0){
                    zeroCount--;
                }
                l++;
            }
            int win = r - l + 1;
            ans = max(ans, win);
        }
        return ans;
    }
};