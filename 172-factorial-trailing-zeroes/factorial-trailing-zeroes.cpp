class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        for(int i=5;i<=1e4;i*=5) cnt+=(n/i);
        return cnt;        
    }
};