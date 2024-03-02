class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans =""; int prev=0;
        for(auto &i:spaces){
            ans+= s.substr(prev,i-prev) + " ";
            prev=i;
        }
        ans+= s.substr(prev);
        return ans;        
    }
};