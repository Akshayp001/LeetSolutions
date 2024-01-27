class Solution {
public:
    int m = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        long long ans=1;
        for(auto &i:nums) pq.push(i);
        while(k!=0){
            int temp = pq.top(); temp+=1;
            pq.pop(); pq.push(temp); k--;
        }
        while(!pq.empty()){
            int temp = pq.top(); pq.pop();
            ans =(ans*temp)%m;
        }
        return ans;
        
    }
};