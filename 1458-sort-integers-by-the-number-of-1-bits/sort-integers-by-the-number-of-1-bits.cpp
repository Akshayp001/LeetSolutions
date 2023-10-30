#include <vector>
#include <algorithm>

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

bool cmp(int a, int b) {
    int ca = countSetBits(a);
    int cb = countSetBits(b);

    if (ca == cb) {
        return a < b;
    }

    return ca < cb;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
