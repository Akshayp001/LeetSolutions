#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dijkstra(vector<vector<pair<int, int>>>& adj, vector<int>& dist, int start) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        dist[start] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        if (n == 1) return true;

        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }

        vector<int> dist(n, INT_MAX);
        dijkstra(adj, dist, s);

        return dist[d] != INT_MAX;
    }
};
