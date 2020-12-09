#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>adj[51];
void dfs(const int dest, int now, vector<string>& words, vector<int>& visit, int cnt, int& ans){
    if(now==dest){
        ans = min(ans, cnt);
        return;
    }
    for(int next:adj[now]){
        if(visit[next]) continue;
        visit[next] = 1;
        dfs(dest, next, words, visit, cnt + 1, ans);
        visit[next] = 0;
    }
}
bool convertable(const string& s, const string& p){
    int n = s.length();
    int cnt = 0;
    for(int i=0;i<n;++i){
        if(s[i]!=p[i]) ++cnt;
    }
    return cnt == 1;
}
int solution(string begin, string target, vector<string> words) {
    int n =words.size();
    int find = -1;
    for(int i=0;i<n;++i){
        if(words[i]==target){
            find = i;
            break;
        }
    }
    if(find==-1) return 0;
    
    vector<int>visit(n);
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(convertable(words[i], words[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int ans = 2147483647;
    for(int i=0;i<n;++i){
        if(convertable(begin, words[i])){
            visit[i] = 1;
            dfs(find, i, words,  visit, 1, ans);
            visit[i] = 0;
        }   
    }
    return ans;
}
