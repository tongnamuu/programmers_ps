#include <string>
#include <vector>
#include <queue>
using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    vector<vector<int>>adj;
    vector<vector<int>>outdegree(n);
    adj.resize(n);
    for(int i=0;i<n-1;++i){
        adj[path[i][0]].push_back(path[i][1]);
        adj[path[i][1]].push_back(path[i][0]);
    }
    vector<int>indegree(n,0);
    vector<int>inQ(n,0);
    vector<bool>visit(n,false);
    for(int i=0;i<order.size();++i){
        outdegree[order[i][0]].push_back(order[i][1]);
        indegree[order[i][1]]++;
    }
    queue<int>q;
    if(indegree[0]) return false;
    q.push(0);
    visit[0]=true;
    int cnt = 0;
    while(!q.empty()){
        int now = q.front();q.pop();++cnt;
        for(int next:outdegree[now]){
            indegree[next]--;
            if(indegree[next]==0 && inQ[next]){
                if(visit[next]) continue;
                q.push(next);
                visit[next]=true;
            }
        }
        for(int next:adj[now]){
            if(visit[next]) continue;
            if(indegree[next]) {
                inQ[next]=true;
                continue;
            }
            q.push(next);
            visit[next]=true;
        }
    }
    return cnt==n;
}
