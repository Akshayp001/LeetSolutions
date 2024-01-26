class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        priority_queue <pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>> > pq;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                int dist = abs(rCenter - i) + abs(cCenter - j);
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                pq.push({dist, temp});
            }
        }
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};