class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastIndex(26,-1);
        int currStart = 0;
        //int currEnd = 0;
        int farthest = 0;
        vector<int>res;

        for(int i=0; i<s.size(); i++){
            lastIndex[s[i]-'a'] = i;
        }

        for(int j=0; j<s.size(); j++){
             farthest = max(farthest, lastIndex[s[j]-'a']);
             if(j==farthest){
                res.push_back(farthest-currStart+1);
                currStart = j + 1;
             }
        }
        return res;
    }
};
