class Solution {
public:
    int canEat(vector<int>& piles, int mid){
        int count = 0;
        for(int i=0; i<piles.size(); i++){
            count += (ceil)((long double)piles[i]/(long double)mid);
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        auto result = std::minmax_element(piles.begin(), piles.end());
        int low = 1;
        int high = *result.second;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(canEat(piles,mid) <= h) high = mid-1;
            else low = mid + 1;
        }
        return low;
    }
};
