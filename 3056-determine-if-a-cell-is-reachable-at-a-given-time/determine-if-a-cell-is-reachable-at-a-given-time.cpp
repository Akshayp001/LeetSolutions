class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t > 1 || t == 0;
        }
        int dis = max(abs(sx - fx), abs(sy - fy));
        return t >= dis;
        
    }
};