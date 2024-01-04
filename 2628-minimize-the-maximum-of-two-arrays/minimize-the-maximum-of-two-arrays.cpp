class Solution {
public:

    long gcd(long a, long b){
        if (b == 0) return a;
        return gcd(b, a % b); 
    }

    void solve(long s, long e, int d1, int d2, long &ans, int m, int n) {
        if (s <= e) {
            long mid = s + (e - s) / 2;
            long a= mid-(mid / d1);
            long b= mid-(mid / d2);
            long l= (long(d1) * long(d2)) / gcd(d1, d2);
            long c= mid-(mid / d1) - (mid / d2) + (mid / l);

            if (a >= m && b >= n && a + b - c >= m + n) {
                ans = mid;
                solve(s, mid - 1, d1, d2, ans, m, n);
            } else {
                solve(mid + 1, e, d1, d2, ans, m, n);
            }
        }
    }

    int minimizeSet(int d1, int d2, int m, int n) {
        long ans = INT_MAX;
        solve(2, INT_MAX, d1, d2, ans, m, n);
        return ans;
    }
};
