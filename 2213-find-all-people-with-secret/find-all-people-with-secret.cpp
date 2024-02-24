class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>> adj[n];
        vector<int> dist(n,INT_MAX);
        dist[0] = 0;
        dist[firstPerson] = 0;
        for(auto i:meetings){
            int a=i[0],b=i[1],time=i[2];
            adj[a].push_back({b,time});
            adj[b].push_back({a,time});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        if(firstPerson != 0) pq.push({0,firstPerson});
        unordered_set<int> s;
        s.insert(0);
        s.insert(firstPerson);
        while(pq.empty() == false){
            pair<int,int> p = pq.top(); pq.pop();
            int d = p.first,curr = p.second;
            s.insert(curr);
            for(auto i:adj[curr])
                if(dist[i.first] > d and i.second >= d  and s.find(i.first) == s.end()){
                    dist[i.first] = i.second;
                    pq.push({i.second,i.first});
                }
            
        }
        vector<int> ans;
        for(auto i:s) ans.push_back(i);
        return ans;
    }
};