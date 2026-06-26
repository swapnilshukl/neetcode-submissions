class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        int count = n;
        int l = 0;
        
        int min_len = INT_MAX, start_idx = -1;

        if(m < n) return "";

        vector<int>freq(256,0);

        for(int i=0; i<n; i++){
            freq[t[i]]++;
        }

        for(int i=0; i<m; i++){
            freq[s[i]]--;
            if(freq[s[i]]>=0) count--;

            while(count == 0){
                if(i-l+1 < min_len){
                    min_len = i - l + 1;
                    start_idx = l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0) count++;
                l++;
            }
        }
        return start_idx == -1 ? "" : s.substr(start_idx, min_len);
    }
};
