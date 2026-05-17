class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < target) return 0;

        //s1 + s2 = sum
        //s1 - s2 = target => s1 = (target + sum)/2

        if((target + sum < 0) || (target + sum)%2 != 0) return 0;
        int finalTarget = (target + sum)/2;

        vector<vector<int>>dp(n+1, vector<int>(finalTarget + 1,0));
        dp[0][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=0; j<=finalTarget; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][finalTarget];
    }
};
