class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxFreq = 0;
        int n = s.length();
        int ans = INT_MIN;

        vector<int>freq(26,0);

        for(int i=0; i<n; i++){
            freq[s[i]-'A']++;
            maxFreq = max(maxFreq, freq[s[i]-'A']);
            int win = i - l + 1;

            while(win - maxFreq > k){
                freq[s[l] - 'A']--;
                l++;
                win = i - l + 1;
            }
            ans = max(ans, win);
        }
        return ans;
    }
};
