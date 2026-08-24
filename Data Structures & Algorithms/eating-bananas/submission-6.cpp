class Solution {
public:
    int solve(vector<int>& piles, int k){
        int total = 0;

        for(int i=0; i<piles.size(); i++){
            total += (ceil)((long double)piles[i]/(long double)k);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            
            if(solve(piles,mid) > h) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
