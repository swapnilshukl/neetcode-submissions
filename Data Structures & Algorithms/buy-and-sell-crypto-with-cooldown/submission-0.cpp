class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int hold = -prices[0];
        int sell = 0;
        int rest = 0;

        for(int i=1; i<prices.size(); i++){
            int prevHold = hold;
            int prevSell = sell;
            int prevRest = rest;

            hold = max(prevHold, prevRest-prices[i]); //keep on holding from yesterday, or buy one today, in these two cases can you keep on holding today
            sell = prevHold + prices[i];
            rest = max(prevRest, prevSell);
        }
        return max(sell, rest);
    }
};
