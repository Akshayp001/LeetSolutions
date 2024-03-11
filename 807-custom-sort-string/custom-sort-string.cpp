#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char,int> m;
    bool cmp(const char &a,const char &b){
        return m[a] < m[b];
    }
    
    string customSortString(string order, string s) {
        m.clear();
        for(int i = 0; i < order.size(); i++) 
            m[order[i]] = i;
        sort(s.begin(), s.end(), [this](const char &a, const char &b) {
            return cmp(a, b);
        });
        return s;
    }
};
