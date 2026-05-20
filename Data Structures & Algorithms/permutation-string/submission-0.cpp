class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m) return false;

        vector<int>s1_freq(26,0);
        vector<int>s2_freq(26,0);

        for(int i=0; i<n; i++){
            s1_freq[s1[i]-'a']++;
            s2_freq[s2[i]-'a']++;
        }
        if(s1_freq == s2_freq) return true;

        for(int i=n; i<m; i++){
            s2_freq[s2[i]-'a']++;
            s2_freq[s2[i-n]-'a']--;

            if(s1_freq == s2_freq) return true;
        }
        return false;
    }
};
