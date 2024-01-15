class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> track;
        vector<vector<int>> ans(2);

        for(auto &i:matches){
            if(track[i[0]]==0) track[i[0]]++;
            if(track[i[1]]==0) track[i[1]]--;
            
            else if(track[i[1]]>0) track[i[1]]=-1;
            else track[i[1]]--;  
        }

        for(auto i:track){
            if(i.second==-1) ans[1].push_back(i.first);
            if(i.second>0) ans[0].push_back(i.first);
        }
        return ans;        
    }
};