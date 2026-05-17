class Solution {
public:
    bool solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];

        if(i == s1.length() && j == s2.length()) return true;

        bool ans = false;

        if(i < s1.length() && s1[i] == s3[i+j])
            ans = solve(i+1, j, s1, s2, s3, dp);
        if(j < s2.length() && s2[j] == s3[i+j])
            ans = solve(i, j+1, s1, s2, s3, dp);

        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;

        vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return solve(0, 0, s1, s2, s3, dp);

    }
};
