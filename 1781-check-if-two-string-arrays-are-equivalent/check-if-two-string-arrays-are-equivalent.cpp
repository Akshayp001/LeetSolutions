class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1;
        string s2;

        for(auto i:word1){
            for(auto j:i){
                s1+=j;
            }
        }

        for(auto i:word2){
            for(auto j:i){
                s2+=j;
            }
        }
        return s1==s2;
    }
};