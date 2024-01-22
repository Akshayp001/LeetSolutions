class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto &i:arr) m[i]++;
        int rep,miss;
        for(int i=1;i<=arr.size();i++){
            if(m[i]==2) rep=i;
            if(m[i]==0) miss=i;
        }
        return {rep,miss};  

    }
};