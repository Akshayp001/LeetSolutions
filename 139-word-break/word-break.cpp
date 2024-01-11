bool cmp(string &s,string &t){
    return s.length()>t.length();
}

class Solution {
public:
    bool solve(string &s, vector<string>& wordDict, int index,vector<int> &dp) {

        if (index == s.length()) {
            return true; 
        }

        if(dp[index]!=-1) return dp[index];

        for (auto word : wordDict) {
            if (s.substr(index, word.length()) == word) {
                if (solve(s, wordDict, index + word.length(),dp)) {
                    return dp[index]=true;
                }
            }
        }
        return dp[index]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1,-1);
        sort(wordDict.begin(),wordDict.end(),cmp);
        return solve(s, wordDict, 0,dp);
    }
};
