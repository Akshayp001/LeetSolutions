class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9 + 7;
        int ct=0;
        for(auto i:corridor){
            if(i=='S'){
                ct++;
            }
        }
        if(ct&1 || ct==0) return 0;
        if(ct==2) return 1;

        vector<int> pcnts;
        int p=0;
        int s=0;

        for(auto ch:corridor){
            if(s==0 || s==1){
                if(ch=='S'){
                    s++;
                    continue;
                }
            }
            if(s==2){
                if(ch=='P'){
                    p++;
                }else{
                    pcnts.push_back(p+1);
                    s=1;
                    p=0;
                }
            }
        }

        long long int ans = 1;
        for(auto i:pcnts){
            ans = (((ans)%mod)*i)%mod;
        }
        return ans;
        
    }
};