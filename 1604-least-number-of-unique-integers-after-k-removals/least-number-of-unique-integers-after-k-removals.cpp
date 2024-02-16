class cmp{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    }
};

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto &i:arr) m[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(auto &i:m) pq.push(i);
        int ans = m.size();

        while(k){
            if(pq.top().second>k) break;
            else{
                k-=pq.top().second;
                pq.pop();
                ans-=1;
            }
        }
        return ans;        
    }
};