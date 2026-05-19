class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int maxi = 0;
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            if(st.find(s[r])!=st.end()){
               
                while(st.count(s[r])){
                    st.erase(s[l++]);
                }
            }
            st.insert(s[r]);
            maxi = max(maxi, r - l + 1); 
        }
        return maxi;
    }
};
