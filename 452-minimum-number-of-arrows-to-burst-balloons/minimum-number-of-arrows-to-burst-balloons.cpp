bool cmp(vector<int> &a,vector<int> &b){
    return (a[1]<b[1]);
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int xbeg=0,xend=0,end=points[0][1];
        int count=1;
        for(auto i:points){
            xbeg = i[0];
            xend = i[1];
            if(xbeg>end){
                count++;
                end = xend;
            }
        }
        return points.size()==0?0:count;
    }
};