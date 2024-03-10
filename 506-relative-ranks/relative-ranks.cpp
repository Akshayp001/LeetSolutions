class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        int n = score.size();
        for(int i=0;i<n;i++) pq.push(make_pair(score[i],i));
        
        vector<string> ans(n);
        int i=0;
        while(!pq.empty()){
            int ind= pq.top().second; pq.pop();
            if(i==0) ans[ind]="Gold Medal";
            else if(i==1) ans[ind]="Silver Medal";
            else if(i==2) ans[ind]="Bronze Medal";
            else ans[ind]=to_string(i+1);
            i++;
        }
        return ans;        
    }
};