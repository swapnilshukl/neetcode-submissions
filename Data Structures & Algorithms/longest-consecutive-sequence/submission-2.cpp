class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        if(n == 0) return 0;
        int maxi = 0;

        for(auto i: nums){
            s.insert(i);
        }

        for(auto it : s){
            if(s.find(it-1)==s.end()){
                int count = 1;
                int x = it;

                while(s.find(x+1)!=s.end()){
                    count++;
                    x++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};
