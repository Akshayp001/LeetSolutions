class Solution {
public:
    int powerOfTwo(int n){
        if(n==0) return -1; 
        if(n<=1) return 0;
        int power=0;
        while (n>1) n/=2,power++;
        return power;
    }
    
    int rangeBitwiseAnd(int left, int right) {
        int t = powerOfTwo(left);
        if (left == right) return left;
        if (t < 0) return 0; 
        if (left == 0) return 0; 
        if (right >= pow(2,t+1)) return 0;
        long long result = left;
        for (long long i=left+1;i<=right;++i) {
            result &= i;
        }
        return result;
    }
};
