class Solution {
public:
    int numberOfMatches(int n) {
        int cnt=0;
        while(n>0){
            if(n==1){
                return cnt;
            }
            if(n&1){
                cnt+=((n-1)/2);
                n = ((n-1)/2) + 1;
            }else{
                cnt+=(n/2);
                n = (n/2) ;
            }
        }

        return -1;
        
    }
};