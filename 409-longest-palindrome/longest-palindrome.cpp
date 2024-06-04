class Solution {
public:
    int longestPalindrome(string s) {
        int count=0;
        unordered_map<char, int> ump;

        for(auto c:s){
            ump[c]++;
        }

        for(auto i:ump){
            if(i.second&1) count++;
        }

        if(count>=1) return (s.length()-count+1);
        else return s.length();
    }
};