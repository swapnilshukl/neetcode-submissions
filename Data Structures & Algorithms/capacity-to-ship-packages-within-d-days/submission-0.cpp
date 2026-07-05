class Solution {
public:
    int solve(int k, vector<int>& weights){
        int total = 1;
        int curr = 0;

        for(int i : weights){
            if(i + curr > k){
                total += 1;
                curr = i;
            }else{
                curr += i;
            }
        }

        return total;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int res;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(solve(mid, weights) > days) low = mid + 1;
            else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};