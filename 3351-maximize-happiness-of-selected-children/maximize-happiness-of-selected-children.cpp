class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios::sync_with_stdio(false);
         cin.tie(nullptr);
         cout.tie(nullptr);
        priority_queue<long long> pq;
        for(auto &i:happiness) pq.push(i);
        long long ans=0,inc=0;
        
        while(!pq.empty()){
            if(k<=0) break;
            if(pq.top()-inc<=0) break;
            ans+=pq.top()-inc; pq.pop();
            inc++; k--;
        }
        return ans;
    }
};