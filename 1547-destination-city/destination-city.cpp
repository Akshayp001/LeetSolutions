class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> m;

        for(auto i:paths){
            m[i[0]]++;
            m[i[1]]++;
        }

        for(auto i:paths){
           if(m[i[1]]==1) return i[1];
        }
        return "";
        
    }
};