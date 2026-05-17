class Solution {
public:
    string minWindow(string s, string t) {

        vector<int>window(256,0), need(256,0);

        for(char c: t){
            need[c]++;
        }

        int left = 0, right = 0;
        int formed = 0;
        int required = t.size();
        int minLen = INT_MAX;
        int start = 0;

        while(right < s.size()){
            char ch = s[right];
            window[ch]++;

            if(window[ch] <= need[ch]) formed++;

            while(formed == required){
                if(right - left + 1 < minLen){
                    minLen = min(minLen, right-left+1);
                    start = left;
                }
                char leftChar = s[left];
                window[leftChar]--;

                if(window[leftChar] < need[leftChar]) formed--;
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "":s.substr(start,minLen);
    }
};
