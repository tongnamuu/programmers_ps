#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#define N 10002
vector<pair<int,int>>adj[N];
string original[N];
vector<string>ans;
void solve(int now){
    for(int i=0;i<adj[now].size();++i){
         if(adj[now][i].second){
            adj[now][i].second = 0;
            solve(adj[now][i].first);
         }
    }
    ans.push_back(original[now]);
}
vector<string> solution(vector<vector<string>> tickets) {
    map<string, int> naming;
    int cnt = 1;
    for(auto& t : tickets) {
        int from, to;
        auto p = naming.find(t[0]);
        if(p==naming.end()) from = naming[t[0]] = cnt++;
        else from = p->second;
        original[from] = t[0];
        
        p = naming.find(t[1]);
        if(p==naming.end()) to = naming[t[1]] = cnt++;
        else to = p->second;
        original[to] = t[1];
        adj[from].push_back({to,1});
    }
    for(int i=1;i<cnt;++i){
        sort(adj[i].begin(), adj[i].end(),[&](const auto& u, const auto& v){
            return original[u.first] < original[v.first];
        });
    }
    int start = naming["ICN"];
    solve(start);
    reverse(ans.begin(), ans.end());
    return ans;
}
