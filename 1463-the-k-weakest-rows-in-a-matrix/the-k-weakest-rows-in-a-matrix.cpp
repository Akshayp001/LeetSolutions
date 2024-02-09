bool cmp(vector<int> &a,vector<int> &b){
        int acnt = 0,bcnt=0;
        for(auto &i:a) acnt+=i;
        acnt-=a[a.size()-1];
        for(auto &i:b) bcnt+=i;
        bcnt-=b[b.size()-1];
        if(acnt==bcnt) return a<b;
        return acnt<bcnt;
    }
class Solution {
public:
   
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        for(int i=0;i<mat.size();i++) mat[i].push_back(i);
        sort(mat.begin(),mat.end(),cmp);
        vector<int> ans;
        int i=0;
        while(k--){
            ans.push_back(mat[i][mat[i].size()-1]);
            i++;
        }
        return ans;
    }
};