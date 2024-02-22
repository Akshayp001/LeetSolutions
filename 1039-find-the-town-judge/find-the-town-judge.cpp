class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        unordered_map<int,int> m;
        unordered_map<int,int> trusted;
        for(auto &i:trust){
            m[i[1]]++;
            trusted[i[0]]=1;
        }
        int ans=-1;
        for(auto &i:m) 
            if(i.second==n-1 && !trusted[i.first]) ans=i.first;
        return ans;
    }
};