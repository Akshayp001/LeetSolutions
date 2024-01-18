bool cmp(const string &a,const string &b){
    return a.length()>b.length();
}

class Solution {
public:
    bool check(string s, string word) {
        if(s.length()<word.length()) return false;
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }
        return j == word.size();
    }



    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int n = dictionary.size();
        sort(dictionary.begin(),dictionary.end(),cmp);
        for (int i=0;i<n;i++) {
            if(dictionary[i].length()<ans.length()) break;
            if (check(s, dictionary[i])) {
                if(ans.length()>0) ans = min(ans,dictionary[i]);
                else ans = dictionary[i];
                if(i+1<n && dictionary[i+1].length()<ans.length()) break; 
            }
        }
        return ans;
    }
};
