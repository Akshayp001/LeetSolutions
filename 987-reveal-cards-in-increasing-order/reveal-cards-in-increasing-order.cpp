class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        sort(deck.begin(),deck.end());
        int n = deck.size();
        for(int i=0;i<n;i++) q.push(i);

        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]=q.front(); q.pop();
            q.push(q.front()); q.pop();
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[v[i]]=deck[i];
        return ans; 
    }
};