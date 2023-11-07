class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> arrivals(n);

        for (int m = 0 ; m < n ; m++) {
            int time = ceil((float)dist[m] / speed[m]);
            if (time >= n) continue;
            arrivals[time]++;
        }
        int i;
        int arrived = 0;
        for (i = 1 ; i < n ; i++) {
            arrived += arrivals[i];
            if (arrived > i) break;
        }
        return i;        
    }
};