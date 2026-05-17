class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>>userTweet;
    unordered_map<int, unordered_set<int>>followMap;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time += 1;
        userTweet[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        priority_queue<vector<int>>maxHeap;

        unordered_set<int>users = followMap[userId];
        users.insert(userId);

        for(int u : users){
            if(userTweet.count(u) && !userTweet[u].empty()){
                int idx = userTweet[u].size()-1;
                auto &tweet = userTweet[u][idx];
                maxHeap.push({tweet.first, tweet.second, u, idx});
            }
        }

        while(!maxHeap.empty() && res.size()<10){
            auto top = maxHeap.top();
            maxHeap.pop();

            int time = top[0];
            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];

            res.push_back(tweetId);

            if(idx-1 >=0){
                auto &nextTweet = userTweet[user][idx-1];
                maxHeap.push({nextTweet.first, nextTweet.second, user, idx-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap.count(followerId)){
            followMap[followerId].erase(followeeId);
        }
    }
};
