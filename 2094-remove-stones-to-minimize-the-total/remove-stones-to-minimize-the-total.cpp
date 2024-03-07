class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto &i:piles) pq.push(i);
        while(k--){
            int t = pq.top(); pq.pop();
            int te = floor(t/2);
            pq.push(t-te);
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=(long long)(pq.top());
            pq.pop();
        }  
        return ans;      
    }
};