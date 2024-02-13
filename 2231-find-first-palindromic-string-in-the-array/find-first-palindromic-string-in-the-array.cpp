class Solution {
public:
    bool check(string word){
        for(int i=0;i<word.size()/2;i++){
            if(word[i]!=word[word.size()-i-1]) return false;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(auto &i:words) if(check(i)) return i;
        return "";
    }
};