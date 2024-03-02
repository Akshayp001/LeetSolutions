class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int ctr=0,i=0,j=0;
        while(i<p.size() && j<t.size()){
            int a=p[i],b=t[j];
            if(a<=b) ctr++,i++,j++;
            else j++;
        }
        return ctr;        
    }
};