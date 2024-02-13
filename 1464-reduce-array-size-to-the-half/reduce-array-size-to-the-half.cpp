class cmp{
    public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        return a.second<b.second;
    }   
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        int n =arr.size();
        for(auto &i:arr) m[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(auto &i:m) pq.push(i);
        int count=0;
        while(n>(arr.size()/2)){
            n-=pq.top().second; pq.pop();
            count++;
        }
        return count;     
    }
};