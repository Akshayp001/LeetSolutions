class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        vector<char> initp(n+1,'n');
        for(int i: left){
            initp[i]='l';
        }
        for(int i: right){
            initp[i]='r';
        }

        int ans=0;

        for(int i=0;i<=n;i++){
            if(initp[i]=='n') continue;

            if(initp[i]=='l'){
                ans = max(ans,abs(i-0));
            }
            if(initp[i]=='r'){
                ans = max(ans,abs(i-n));
            }
        }
        return ans;
    }
};