class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        int startIndex = 0;

        int totalGas = 0;
        int totalCost = 0;

        for(int i=0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i];

            tank += gas[i] - cost[i];

            if(tank < 0){
                startIndex = i + 1;
                tank = 0;
            }
        }
        if(totalGas < totalCost) return -1;
        return startIndex;
    }
};
