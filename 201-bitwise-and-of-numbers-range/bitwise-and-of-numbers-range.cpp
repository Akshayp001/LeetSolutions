class Solution {
public:
    int log2(int n){
        if(n==0) return -1; 
        if(n<=1) return 0;
        int power=0;
        while (n>1) n/=2,power++;
        return power;
    }
    
    int rangeBitwiseAnd(int left, int right) {
        int t = log2(left);
        if (left == right) return left;
        if (left==0 || t<0) return 0; 
        if (right >= pow(2,t+1)) return 0;
        long long result = left;
        for (long long i=left+1;i<=right;++i) result &= i;
        return result;
    }
};
