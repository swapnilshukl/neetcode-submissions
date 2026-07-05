class Solution {
public:
    int canEat(int mid, vector<int>& piles){
        int total = 0;
        for(int i : piles){
            total += (ceil)((long double)i/(long double)mid);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        auto high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high-low)/2;

            if(canEat(mid, piles) > h){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};
