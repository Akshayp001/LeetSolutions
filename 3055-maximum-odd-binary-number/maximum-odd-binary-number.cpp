class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        s= s.substr(1)+s[0];
        return s;
    }
};