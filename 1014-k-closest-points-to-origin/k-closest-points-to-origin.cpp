bool cmp(const vector<int> &a,const vector<int> &b){
    double aa = sqrt((a[0]*a[0])+(a[1]*a[1]));
    double bb = sqrt((b[0]*b[0])+(b[1]*b[1]));
    return aa<bb;
}


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),cmp);
        vector<vector<int>> ans(points.begin(),points.begin()+k);
        return ans;
    }
};