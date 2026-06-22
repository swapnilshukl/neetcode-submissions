class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0;

        for(int num : st){
            if(st.find(num-1)==st.end()){
                int currNum = num;
                int count = 1;

                while(st.find(currNum+1)!=st.end()){
                    currNum += 1;
                    count++;
                }

                ans = max(ans, count);
            }
        }
        return ans;
    }
};
