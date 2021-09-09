#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 2140000000
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
int a[4][4];
int map[4][4];
int visit[4][4];
vector<pair<int,int>>pos[7];
int X, Y;
void init() {
    for(int i=0;i<4;++i) for(int j=0;j<4;++j) visit[i][j] = -1;
}
bool range(int x, int y) {
    return x>=0&&x<4&&y>=0&&y<4;
}

int bfs(int sx, int sy, int ex, int ey) {
    init();
    queue<pair<int,int>>q;
    q.push({sx,sy});
    visit[sx][sy] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        bool find = false;
        for(int i=x - 1;i>=0;--i) {
            if(a[i][y] > 0){                
                if(visit[i][y]==-1){
                    q.push({i,y});
                    visit[i][y] = visit[x][y] + 1;
                }
                find = true;
                break;
            }
        }
        if(!find) {
            if(visit[0][y]==-1){
                q.push({0,y});
                visit[0][y] = visit[x][y] + 1;
            }
        }
        
        find =false;
        for(int i=x + 1;i<4;++i) {
            if(a[i][y] > 0 ){
                if(visit[i][y]==-1){
                    q.push({i,y});
                    visit[i][y] = visit[x][y] + 1;
                }
                find = true;
                break;
            }
        }
        if(!find) {
            if(visit[3][y]==-1){
                q.push({3,y});
                visit[3][y] = visit[x][y] + 1;
            }
        }
        find =false;
        for(int i=y - 1;i>=0;--i) {
            if(a[x][i] > 0){
                if(visit[x][i]==-1){
                    q.push({x,i});
                    visit[x][i] = visit[x][y] + 1;
                }
                find = true;
                break;
            }
        }
        if(!find) {
            if(visit[x][0]==-1){
                q.push({x,0});
                visit[x][0] = visit[x][y] + 1;
            }
        }
        find = false;
        for(int i=y + 1;i<4;++i) {
            if(a[x][i] > 0){
                if(visit[x][i]==-1){
                    q.push({x,i});
                    visit[x][i] = visit[x][y] + 1;
                }
                find = true;
                break;
            }
        }
        if(!find) {
            if(visit[x][3]==-1){
                q.push({x,3});
                visit[x][3] = visit[x][y] + 1;
            }
        }
        for(int dir=0;dir<4;++dir){
            int nx =x+dx[dir];
            int ny = y +dy[dir];
            if(!range(nx,ny)||visit[nx][ny]!=-1) continue;
            q.push({nx,ny});
            visit[nx][ny] = visit[x][y] + 1;
        }
    }
    return visit[ex][ey];
}

void fill(vector<pair<int,int>>& seq, int seqIdx, int idx, vector<int>& p, int& ans) {
    if(seqIdx>=seq.size()) {
        int n = seq.size();
        int prevx=X;
        int prevy=Y;
        int temp = seq.size();
        int state = 0;
        for(int i=0;i<4;++i) for(int j=0;j<4;++j) a[i][j] = map[i][j];
        for(int i=0;i<n;i+=2) {
            temp += bfs(prevx, prevy, seq[i].first, seq[i].second);
            temp += bfs(seq[i].first, seq[i].second, seq[i+1].first, seq[i+1].second);      
            a[seq[i].first][seq[i].second] = 0;
            a[seq[i+1].first][seq[i+1].second] = 0;
            prevx = seq[i+1].first;
            prevy = seq[i+1].second;
        }
        ans = min(ans, temp);
        return;
    }
    seq[seqIdx] = pos[p[idx]][0];
    seq[seqIdx+1] = pos[p[idx]][1];
    fill(seq, seqIdx+2,idx+1, p, ans);
    seq[seqIdx] = pos[p[idx]][1];
    seq[seqIdx+1] = pos[p[idx]][0];
    fill(seq, seqIdx+2,idx+1, p, ans);
}

int solution(vector<vector<int>> board, int r, int c) {
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            map[i][j] = a[i][j] = board[i][j];
            if(a[i][j]) {
                pos[a[i][j]].push_back({i,j});
            }
        }
    }
    X=r;Y=c;
    vector<int>p;
    for(int i=1;i<=6;++i) {
        if(pos[i].size()==2) p.push_back(i);
    }
    vector<pair<int,int>> seq(p.size()*2);
    int ans = INF;
    do{
        fill(seq, 0, 0, p, ans);
    }while(next_permutation(p.begin(), p.end()));
    return ans;
}
