class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> winners;
        unordered_map<int,int> loosers;
        vector<vector<int>> ans(2);

        for(auto &i:matches){
            winners[i[0]]++;
            loosers[i[1]]++;
        }

        for(auto &i:winners)
            if(loosers[i.first]==0)    
                ans[0].push_back(i.first);
        
        for(auto &j:loosers) if(j.second==1) ans[1].push_back(j.first);

        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;        
    }
};