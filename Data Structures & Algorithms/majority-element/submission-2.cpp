class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int ele = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i] == ele && cnt > 0){
                cnt++;
            }else if(nums[i]!=ele && cnt > 0){
                cnt--;
            }else if(cnt == 0){
                ele = nums[i];
                cnt = 1;
            }
        }
        return ele;
    }
};