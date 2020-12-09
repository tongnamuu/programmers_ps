#include <string>
#include <vector>

using namespace std;

void dfs(int now, const int n, const vector<vector<int>>& adj, vector<int>& visit){
    visit[now] = 1;
    for(int i=0;i<n;++i){
        if(!visit[i] && adj[now][i]){
            dfs(i, n, adj, visit);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    vector<int>visit(n);
    int ans = 0;
    for(int i=0;i<n;++i){
        if(!visit[i]){
            ++ans;
            dfs(i, n, computers, visit);
        }
    }
    return ans;
}
