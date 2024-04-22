#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        int steps = 0;
        
        q.push("0000");
        visited.insert("0000");
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();
                
                if (dead.count(current)) continue;
                if (current == target) return steps;
                
                for (int j = 0; j < 4;j++) {
                    string up = current, down = current;
                    up[j] = (up[j] == '9') ? '0' : up[j] + 1;
                    down[j] = (down[j] == '0') ? '9' : down[j] - 1;
                    
                    if (!visited.count(up) && !dead.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    
                    if (!visited.count(down) && !dead.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
