class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> arr;
        for(int i=0;i<points.size();i++) arr.push_back(points[i][0]);
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<arr.size()-1;i++) ans=max(ans,arr[i+1]-arr[i]);
        return ans;
    }
};