class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &i:queries){
            int x=i[0],y=i[1],r=i[2];
            int cnt=0;
            for(auto &pt:points){
                int a=pt[0],b=pt[1];
                double dist = sqrt(pow(x-a,2)+pow(y-b,2));
                if(dist<=r) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};