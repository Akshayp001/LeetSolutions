class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        vector<int> m(26,0);
        q.push(0); m[s[0]-'a'];
        m[s[0]-'a']++;
        for(int i=1;i<s.length();i++){
            m[s[i]-'a']++;
            q.push(i);
            while(!q.empty() && m[s[q.front()]-'a']>1) q.pop();
        }

        //using hashtable
        // unordered_map<char,int> um;

        // for(char i:s){
        //     um[i]++;            
        // }

        // for(int i=0;i<s.length();i++){
        //     if(um[s[i]]==1){
        //         return i;
        //     }
        // }
        return q.empty()?-1:q.front();
    }
};