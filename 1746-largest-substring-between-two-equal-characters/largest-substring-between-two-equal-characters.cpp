class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,vector<int>> m;
    
        for(int i=0;i<s.length();i++){
            m[s[i]].push_back(i);
        }

        int maxi=-1;
        for(auto mi:m){
            cout<<mi.second.size()<<endl;
            if(mi.second.size()>1){
                maxi = max(maxi,mi.second[mi.second.size()-1]-mi.second[0]-1);
            }
        }
        return maxi; 
    }
};