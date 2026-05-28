class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>>store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";
        
        auto &value = store[key];

        int n = value.size();
        string ans = "";

        int l = 0;
        int r = n - 1;

        while(l <= r){
            int m = l + (r-l)/2;

            if(value[m].first <= timestamp){
                ans = value[m].second;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return ans;
    }
};
