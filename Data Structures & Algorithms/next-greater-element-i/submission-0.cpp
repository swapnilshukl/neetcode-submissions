class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans(n);
        stack<int>st;
        unordered_map<int,int>mp;

        for(int i=m-1; i>=0; i--){
            int currEle = nums2[i];

            while(!st.empty() && currEle > st.top()){
                st.pop();
            }

            if(!st.empty()) mp[nums2[i]] = st.top();
            else mp[nums2[i]] = -1;
            st.push(nums2[i]);
        }

        for(int i=0; i<n; i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};