#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26, 0);
        for (auto &i: tasks) {
            hash[i - 'A']++;
        }
        
        priority_queue<int> pq; 
        for (auto i : hash) {
            if (i > 0) {
                pq.push(i);
            }
        }
        int itrs = 0;
        while (!pq.empty()) {
            vector<int> t; 
            int i = 0;
            while (i <= n) {
                if (!pq.empty()) {
                    if (pq.top() > 1) t.push_back(pq.top() - 1);  
                    pq.pop();
                }
                itrs++;
                if (pq.empty() && t.empty()) break;
                i++;
            }
            for (int t : t) {
                pq.push(t); 
            }
        }
        
        return itrs;
    }
};
