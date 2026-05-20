class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int>freq(128,0);
        string res = "";
        if(n < m) return "";
        int cnt = m;
        int l = 0, min_len = INT_MAX, start_idx = -1;

        for(int i=0; i<m; i++){
            freq[t[i]]++;
        }

        for(int i=0; i<n; i++){
            if(freq[s[i]]>0) cnt--;
            freq[s[i]]--;
            
            
            while(cnt == 0){
                if(i - l + 1 < min_len){
                    min_len = i - l + 1;
                    start_idx = l;
                }
                freq[s[l]]++;
                if(freq[s[l]]> 0) cnt++;
                l++;
            }
            
            
        }
        return start_idx == -1 ? "" : s.substr(start_idx, min_len);
    }
};
