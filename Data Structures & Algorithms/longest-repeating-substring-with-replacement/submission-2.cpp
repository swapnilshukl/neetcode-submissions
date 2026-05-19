class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxFreq = 0;
        int ans = INT_MIN;
        int  l = 0;
        
        vector<int>freq(26,0);
        for(int i=0; i<n; i++){
            freq[s[i]-'A']++;
            maxFreq = max(maxFreq, freq[s[i]-'A']);
            int window = i - l + 1;

            while(window - maxFreq > k){
                freq[s[l]-'A']--;
                l++;
                window = i - l + 1;
            }
            ans = max(ans, window);
        }
        return ans;
    }
};
