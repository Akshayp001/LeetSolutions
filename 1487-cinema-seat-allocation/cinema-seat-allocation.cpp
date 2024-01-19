#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int poss(vector<int>& arr) {
        bool one = true, two = true, three = true;
        for (int i = 1; i <= 4; i++) if (arr[i]) one = false;
        for (int i = 3; i <= 6; i++) if (arr[i]) two = false;
        for (int i = 5; i <= 8; i++) if (arr[i]) three = false;

        if (one && three) return 2;
        if (one || two || three) return 1;
        return 0;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        sort(seats.begin(), seats.end());
        long long ans = 0;

        long long c = 1;
        long long ind = 0;
        while (ind < seats.size() && c <= n) {
            if (seats[ind][0] != c) {
                long long temp = seats[ind][0] - c;
                temp *= 2;
                c = seats[ind][0];
                ans += temp;
                continue;
            }
            else {
                vector<int> v(10, 0);
                while (ind < seats.size() && seats[ind][0] == c) {
                    v[seats[ind][1] - 1] = 1;
                    ind++;
                }
                ans += poss(v);
            }
            c++;
        }

        while (c <= n) {
            ans += 2;
            c++;
        }

        return ans;
    }
};
