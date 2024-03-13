class Solution {
public:
    int pivotInteger(int n) {
        // if(n==1) return 1;
        // int s = n*(n+1)/2; 
        // for(int i=1;i<n;i++){
        //     int t= i*(i+1)/2;
        //     if((s-t+i)==t) return i;
        // }
        // return -1;
        int s=1,e=n;
        int sum = n*(n+1)/2;
        int m,l,r;
        while(s<=e){
            m = s+ (e-s)/2;
            l = m*(m+1)/2;
            r = sum-(l-m);
            if(r==l) return m;
            else if(l>r) e=m-1;
            else s=m+1;
        }
        return -1;
    }
};