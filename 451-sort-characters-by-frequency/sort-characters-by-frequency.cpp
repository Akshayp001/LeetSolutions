class cmp{
    public:
    bool operator()(const pair<char,int>&a,const pair<char,int> &b){
        return a.second<b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        string ans="";
        for(auto &c:s) m[c]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq;
        for(auto &i:m) pq.push(i);
        while(!pq.empty()){
            pair<char,int> temp=pq.top();
            pq.pop();
            for(int i=0;i<temp.second;i++){
                ans+=temp.first;
            }
        }
        return ans;
    }
};