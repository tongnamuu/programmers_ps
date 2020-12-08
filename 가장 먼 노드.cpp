#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int>dist(n+1, -1);
    vector<vector<int>>adj(n+1);
    for(auto& e : edge){
        int from = e[0];
        int to = e[1];
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    queue<int>q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int now = q.front();q.pop();
        for(int next:adj[now]){
            if(dist[next]==-1){
                q.push(next);
                dist[next] = dist[now] + 1;
            }
        }
    }
    int ans = 0;
    int cur_dist = 0;
    for(int i=1;i<=n;++i){
        if(cur_dist == dist[i]){
            ans++;
        }
        else if(cur_dist < dist[i]){
            ans = 1;
            cur_dist = dist[i];
        }
    }
    return ans;
}
