class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        int s = n*(n+1)/2; 
        for(int i=1;i<n;i++){
            int t= i*(i+1)/2;
            if((s-t+i)==t) return i;
        }
        return -1;
    }
};