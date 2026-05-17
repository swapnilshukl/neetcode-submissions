class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char t: tasks){
            freq[t-'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCount = 0;

        for(int f: freq){
            if(f == maxFreq) maxCount++;
        }

        int partCount = maxFreq - 1;
        int partLen = n + 1;
        int minTime = partCount * partLen + maxCount;
        return max((int)tasks.size(), minTime);
    }
};
