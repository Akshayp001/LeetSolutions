class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<int> m(n+1,0);
        vector<int> trusted(n+1,0);
        for(auto &i:trust){
            m[i[1]]++;
            trusted[i[0]]=1;
        }
        int ans=-1;
        for(int i=1;i<=n;i++) 
            if(m[i]==n-1 && !trusted[i]) ans=i;
        return ans;
    }
};