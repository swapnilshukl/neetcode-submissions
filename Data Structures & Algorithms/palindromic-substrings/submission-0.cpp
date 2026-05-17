class Solution {
public:
    int count = 0;
    int checkPalindrome(string s, int i, int j){
        while(i >=0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        if(s.empty()) return 0;

        for(int i=0; i<s.length(); i++){
            checkPalindrome(s, i, i);
            checkPalindrome(s, i, i+1);
        }
        return count;
    }
};
