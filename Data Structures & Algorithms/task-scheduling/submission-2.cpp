class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(int t: tasks){
            freq[t-'A']++;
        }
        priority_queue<int>maxHeap;
        for(int f: freq){
            if(f>0) maxHeap.push(f);
        }

        queue<pair<int,int>>q;
        int time = 0;

        while(!maxHeap.empty() || !q.empty()){
            time++;
            if(!maxHeap.empty()){
                int count = maxHeap.top();
                maxHeap.pop();
                count--;

                if(count > 0){
                    q.push({count, time+n});
                }
            }
            if(!q.empty() && q.front().second == time){
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
