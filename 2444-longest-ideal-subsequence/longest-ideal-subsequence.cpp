class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> v(26);

        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a';

            int l = max(0, val - k);
            int h = min(25, val + k);

            int maxi = 0;

            for (int j = l; j <= h; j++) {
                maxi = max(maxi, v[j]);
            }

            v[val] = maxi + 1;
        }

        int max = INT_MIN;
        for (int i = 0; i < 26; i++) {
            if (v[i] > max)
                max = v[i];
        }

        return max;
    }
};