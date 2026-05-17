class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>>adj;
        unordered_map<char,int>inDegree;
        for(auto word : words){
            for(auto c : word){
                inDegree[c] = 0;
            }
        }

        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for(int j=0; j<len; j++){
                if(w1[j]!=w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    inDegree[w2[j]]++;
                    found = true;
                    break;
                }
            }

            if(!found && w1.size() > w2.size()) return "";
        }
        queue<char>q;
        for(auto &p : inDegree){
            if(p.second == 0) q.push(p.first);
        }
        string res;

        while(!q.empty()){
            char node = q.front();
            q.pop();
            res += node;

            for(char nei : adj[node]){
                inDegree[nei]--;
                if(inDegree[nei] == 0) q.push(nei);
            }
        }

        if(res.size()!= inDegree.size()) return "";
        return res;
    }
};
