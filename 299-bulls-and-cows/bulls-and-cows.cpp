class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> s,g;
        int x=0,y=0;
        int n = secret.length();
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) x++;
            else{
                s[secret[i]]++;
                g[guess[i]]++;
            }
        }

        for(auto si:s){
            if(g[si.first]>0){
                y+=min(si.second,g[si.first]);
            }
        }
        string ans="";
        ans+= to_string(x);
        ans+='A';
        ans+= to_string(y);
        ans+='B';

        return ans;       
    }
};