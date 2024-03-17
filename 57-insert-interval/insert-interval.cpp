class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int f = newInterval[0];
        int s = newInterval[1];
        int flag = 0;
        vector<vector<int>> result;

        for (int i = 0; i < intervals.size(); i++) {
            if (f > intervals[i][1]) {
                result.push_back(intervals[i]);
            } else if (s < intervals[i][0]) {
                if (flag == 0) {
                    result.push_back({f, s});
                    flag = 1;
                }
                while (i < intervals.size()) {
                    result.push_back(intervals[i]);
                    i++;
                }
            } else {
                f = min(f, intervals[i][0]);
                s = max(s, intervals[i][1]);
            }
        }

        if (flag == 0) {
            result.push_back({f, s});
        }

        return result;
    }
};
