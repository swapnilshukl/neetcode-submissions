class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(s.empty()) return "";
        int maxLen = 0;
        string res = "";

        for(int mid = 0; mid < n; mid++){
            for(int x = 0; mid-x >=0 && mid+x<n; x++){
                if(s[mid-x]!=s[mid+x]) break;
                int len = 2*x+1;
                if(len > maxLen){
                    maxLen = len;
                    res = s.substr(mid-x, len);
                }
            }

            for(int x=1; mid-x+1>=0 && mid+x<n; x++){
                if(s[mid-x+1]!=s[mid+x]) break;
                int len = 2*x;
                if(len > maxLen){
                    maxLen = len;
                    res = s.substr(mid-x+1, len);
                }
            }
        }
        return res;
    }
};
