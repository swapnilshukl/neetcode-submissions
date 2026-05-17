class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found_x = false;
        bool found_y = false;
        bool found_z = false;

        for(auto it: triplets){
            int a = it[0];
            int b = it[1];
            int c = it[2];

            if(a > target[0] || b > target[1] || c > target[2]) continue;

            if(a == target[0]) found_x = true;
            if(b == target[1]) found_y = true;
            if(c == target[2]) found_z = true;

            
            
        }
        return (found_x && found_y && found_z);
    }
};
