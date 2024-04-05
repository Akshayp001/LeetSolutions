#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for (char c : s) {
            if (!ans.empty() && tolower(ans.back()) == tolower(c) && ans.back() != c) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
