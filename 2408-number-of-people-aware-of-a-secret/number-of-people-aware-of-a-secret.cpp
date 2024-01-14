#define ll long long
#define M 1000000007

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> arr(forget, 0); 
        arr[0] = 1;

        for (int i = 2; i <= n; i++) {
            int newPeoples = 0;

            for (int j = arr.size() - 1; j > 0; j--) {
                arr[j] = arr[j - 1];
                if (j >= delay) newPeoples = (newPeoples + arr[j]) % M;
            }

            arr[0] = newPeoples;
        }

        ll ans = 0;
        for (auto i : arr) {
            ans = (ans + i) % M;
        }
        return ans;
    }
};
