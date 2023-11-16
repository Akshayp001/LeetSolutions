class Solution {
public:
    int strToInt(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < s.length(); i++) {
            int j = n - i - 1;
            if (s[j] == '1') ans += 1 << i;
        }
        return ans;
    }

    string intToBinaryString(int n, int length) {
        if (n == 0) return string(length, '0');

        string result = "";
        while (n > 0) {
            result = (n % 2 == 0 ? "0" : "1") + result;
            n /= 2;
        }

        while (result.length() < length) {
            result = '0' + result;
        }

        return result;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].length();
        int maxi = (1 << n) - 1;

        unordered_map<int, int> mp;
        for (const auto& i : nums) {
            mp[strToInt(i)]++;
        }

        string ans;
        for (int i = 0; i <= maxi; i++) {
            if (mp[i] == 0) {
                ans = intToBinaryString(i, n);
                break;
            }
        }

        return ans;
    }
};