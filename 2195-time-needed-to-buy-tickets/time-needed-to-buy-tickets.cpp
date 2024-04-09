class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int n =tickets.size();
        for(int i=0;i<n;i++) q.push(make_pair(i,tickets[i]));
        int time=0;
        while(!q.empty()){
            auto t = q.front(); q.pop();
            t.second=t.second-1;
            if(t.second>0) q.push(t);
            else{
                if(t.first==k) return time+1;
            }
            time++;
        }
        return -1;
         
    }
};