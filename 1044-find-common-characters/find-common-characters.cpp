class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        int arr[26];
        for(int i=0; i<26; i++)arr[i] = INT_MAX;
        for(string s:words){
            int curr[26]{0};
            for(char c:s){
                curr[c-'a']++; 
            }
            for(int i=0; i<26; i++){
                arr[i] = min(arr[i],curr[i]);
            }
        }
        for(int i=0; i<26; i++){
            for(int j=0; j<arr[i]; j++){
                char c = static_cast<char>('a'+i);
                string s = "";
                s += c;
                ans.push_back(s);
            }
        }
        return ans;
    }
};