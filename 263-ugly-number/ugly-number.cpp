class Solution {
public:
    unordered_map<int, int> factors(int n) {
        unordered_map<int, int> m;
        for (long long i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                m[i]++;
            }
        }
        if (n > 1) m[n]++;
        return m;
    }
    
    bool isUgly(int n) {
        unordered_map<int,int> m;
        m=factors(n);
        for(auto &i:m){
            if(i.first!=2 && i.first!=5 && i.first!=3){  
                return false;
            }
        }
        return true&&n>0;        
    }
};