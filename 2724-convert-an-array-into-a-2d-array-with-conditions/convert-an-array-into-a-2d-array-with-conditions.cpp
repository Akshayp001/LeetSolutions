struct ComparePairs {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }
};


class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int, int>>, ComparePairs> pq;

        for(auto i:nums) m[i]++;

        for(auto i:m) pq.push(i);

        vector<vector<int>> ans(pq.top().second,vector<int>());
        while(!pq.empty()){
            int t = pq.top().first;
            for(int i=0;i<m[t];i++){
                ans[i].push_back(t);
            }
            pq.pop();
        }
        return ans;

    }
};