class Solution {
public:
    void mark(char c, int &i, int &j) {
        if (c == 'N') j++;
        if (c == 'E') i++;
        if (c == 'S') j--;
        if (c == 'W') i--;
    }

    struct PairHash {
        template <class T1, class T2>
        size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    bool isPathCrossing(string path) {
        unordered_map<pair<int, int>, int, PairHash> m;
        m[{0, 0}]++;
        int i = 0, j = 0;
        for (auto c : path) {
            mark(c, i, j);
            if (m[{i, j}] >= 1) {
                return true;
            } else {
                m[{i, j}]++;
            }
        }
        return false;
    }
};
