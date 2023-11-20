class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b, int k) {
        return a[k] > b[k]; 
    }

    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [k](const vector<int> &a, const vector<int> &b) {
            return cmp(a, b, k);
        });

        return score;
    }
};
