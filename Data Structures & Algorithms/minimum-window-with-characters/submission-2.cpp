class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int count = t.size();
        vector<int>freq(128,0);
        int minWin = INT_MAX;
        int startIndex = 0;

        for(auto it: t){
            freq[it]++;
        }

        for(int right = 0; right < s.size(); right++){
            char ch = s[right];
            if(freq[ch]>0){
                count--;
            }
            freq[ch]--;
            while(count == 0){
                if(right-left+1 < minWin){
                    minWin = right - left +1;
                    startIndex = left;
                }
                char leftChar = s[left];
                freq[leftChar]++;

                if(freq[leftChar]>0) count++;
                left++;
            }
        }
        return minWin == INT_MAX ? "" : s.substr(startIndex, minWin);
    }
};
