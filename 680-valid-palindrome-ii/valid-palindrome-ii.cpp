class Solution {
public:
    bool isPal(const string& str, int start, int end) {
        while (start < end) {
            if (str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        
        while (start < end) {
            if (s[start] != s[end]) {
                return isPal(s, start + 1, end) || isPal(s, start, end - 1);
            }
            start++;
            end--;
        }
        return true;
    }
};
