class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m,occ;

        for(auto i:arr) m[i]++;
        for(auto i:m){
            occ[i.second]++;
            if(occ[i.second]>1){
                return false;
            }
        }
        return true;
    }
};
