class Twitter {
private:
   
public:
    deque<pair<int,int>>dq,tmp;
    map<int,vector<int>>ma;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        dq.push_front({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        tmp=dq;
        int k=10;
        auto x=ma[userId];
        map<int,int>hash;
        for(auto i:x){
        
            hash[i]=1;
        }
        while(!tmp.empty() and k!=0)
        {
       
            auto x=tmp.front();
            if(x.first==userId or hash[x.first]){
                ans.push_back(x.second);
                k--;
            }
            tmp.pop_front();
        
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        ma[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        
        vector<int>followers=ma[followerId];
        auto it=find(followers.begin(),followers.end(),followeeId);
        if(it==followers.end())
            return;
        followers.erase(it);
        ma[followerId]=followers;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */