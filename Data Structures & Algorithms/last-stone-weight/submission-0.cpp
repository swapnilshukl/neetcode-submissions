class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(int s: stones){
            pq.push(s);
        }

        while(pq.size()>1){
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            if(t1 == t2) continue;
            else if(t1 > t2) pq.push(t1-t2);
            else pq.push(t2-t1);
        }
        if(!pq.empty()) return pq.top();
        else return 0;
    }
};
