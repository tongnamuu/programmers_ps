#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define INF 1000000000
struct Edge {
    int v;
    int c;
    bool operator<(const Edge& a) const {
        return this->c > a.c;
    }
};
long long first[201];
long long second[201];
long long start[201];
void dijk(int n, int s,long long *dist, const vector<vector<Edge>>& adj) {
    priority_queue<Edge>q;
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }
    dist[s] = 0;
    q.push({ s,0 });
    while (!q.empty()) {
        int now = q.top().v;
        int c = q.top().c;
        q.pop();
        if (dist[now] < c) continue;
        for (auto p : adj[now]) {
            int next = p.v;
            int nc = c + p.c;
            if (dist[next] > nc) {
                dist[next] = nc;
                q.push({ next, nc });
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<Edge>>adj(n + 1);
    for (auto& v : fares) {
        int from = v[0];
        int to = v[1];
        int c = v[2];
        adj[from].push_back({ to,c });
        adj[to].push_back({ from, c });
    }
    dijk(n, s, start, adj);
    dijk(n, a, first, adj);
    dijk(n, b, second, adj);
    long long v1 = start[a] + first[b];
    long long v2 = start[b] + second[a];
    long long v3 = start[a] + start[b];
    long long ans = min({ v1, v2, v3 });
    for (int i = 1; i <= n; ++i) {
        ans = min(start[i] + first[i] + second[i], ans);
    }
    return ans;
}
