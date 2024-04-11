
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (char c : num) {
            while (k > 0 && !ans.empty() && ans.back() > c) {
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        int nzs = 0;
        while (nzs < ans.size() && ans[nzs] == '0') nzs++;
        ans = ans.substr(nzs);
        return ans.empty() ? "0" : ans;
    }
};
