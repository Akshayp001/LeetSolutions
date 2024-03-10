class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<long long> pq;
        for(auto &i: stones){
            pq.push(i);
        }
        while(pq.size()>=2){
            long long a= pq.top(); pq.pop();
            long long b= pq.top(); pq.pop();
            if(a==b) continue;
            pq.push(abs(a-b));
        }
        return pq.empty()?0:pq.top();   
    }
};