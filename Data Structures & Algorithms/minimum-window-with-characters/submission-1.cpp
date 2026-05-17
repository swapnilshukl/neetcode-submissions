class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128,0);
        for(char c: t){
            freq[c]++;
        }
        int left = 0, right = 0;
        int req = t.size();

        int minLen = INT_MAX;
        int startIndex = 0;

        while(right < s.size()){
            char ch = s[right];
            if(freq[ch] > 0){
                req--;
            }
            freq[ch]--;

            while(req == 0){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    startIndex = left;
                }

                char leftChar = s[left];
                freq[leftChar]++;

                if(freq[leftChar]>0){
                    req++;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "":s.substr(startIndex,minLen);
    }
};
