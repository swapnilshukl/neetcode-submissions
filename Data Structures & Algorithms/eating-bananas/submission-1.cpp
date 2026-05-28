class Solution {
public:
    int solve(vector<int>& piles, int k){
        int total = 0;

        for(int i : piles){
            total += (ceil)((long double)(i)/(long double)k);
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        auto high = *std::max_element(piles.begin(), piles.end());

        while(low <= high){
            int k = (low + high)/2;

            if(solve(piles,k) <= h) high = k-1;
            else if(solve(piles, k) > h) low = k+1;
            
        }
        return low;
    }
};
