#include <string>
#include <vector>
#include <queue>
#include <vector>
using namespace std;
struct Mode {
    int x, y, garo;
    pair<int, int> getPos() {
        if(garo) {
            return {x, y + 1};
        } else{
            return {x - 1, y};
        }
    }
};
int d[101][101][2];
int a[101][101];
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
int n;
bool range(int x, int y) {
    return x>=0 && x<n&&y>=0&&y<n;
}
bool place(int x, int y, int nx, int ny) {
    return range(x,y) && range(nx,ny) && a[x][y] == 0 && a[nx][ny] == 0;
}

int solution(vector<vector<int>> board) {
    n = board.size();
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) a[i][j] = board[i][j];
    }
    queue<Mode>q;
    q.push({0,0,1});
    d[0][0][1] = 1;
    int nx, ny, nnx,nny;
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int garo = q.front().garo;
        q.pop();
        if(garo) {
            // 오른쪽
            nx = nnx =x;
            ny = y + 1;
            nny = y + 2;
            if(place(nx,ny, nnx, nny) && !d[nx][ny][garo]) {
                d[nx][ny][garo] = d[x][y][garo] + 1;
                q.push({nx,ny,garo});
            }
            // 왼쪽
            ny = y - 1;
            nny = y;
            if(place(nx,ny, nnx, nny) && !d[nx][ny][garo]) {
                d[nx][ny][garo] = d[x][y][garo] + 1;
                q.push({nx,ny,garo});
            }
            // 위
            nx = nnx = x - 1;
            ny = y;
            nny = y + 1;
            if(place(nx,ny, nnx, nny) && !d[nx][ny][garo]) {
                d[nx][ny][garo] = d[x][y][garo] + 1;
                q.push({nx,ny,garo});
            }
            // 아래
            nx = nnx = x + 1;
            if(place(nx,ny, nnx, nny) && !d[nx][ny][garo]) {
                d[nx][ny][garo] = d[x][y][garo] + 1;
                q.push({nx,ny,garo});
            }
            // 회전
            if(range(x+1,y+1) && a[x][y] == 0 && a[x][y+1]==0&&a[x+1][y] ==0 && a[x+1][y+1]==0) {
                if(d[x+1][y+1][0]==0) {
                    d[x+1][y+1][0] = d[x][y][1] + 1;
                    q.push({x+1,y+1,0});
                }
                if(d[x+1][y][0]==0) {
                    d[x+1][y][0] = d[x][y][1] + 1;
                    q.push({x+1,y,0});
                }
            }
            if(range(x-1,y+1) && a[x][y] == 0 && a[x][y+1]==0&&a[x-1][y] ==0 && a[x-1][y+1]==0) {
                if(d[x][y+1][0]==0) {
                    d[x][y+1][0] = d[x][y][1] + 1;
                    q.push({x,y+1,0});
                }
                if(d[x][y][0]==0) {
                    d[x][y][0] = d[x][y][1] + 1;
                    q.push({x,y,0});
                }
            }
        } else {
            //오
            nx = x;
            nnx = x - 1;
            ny=nny = y + 1;
            if(place(nx,ny, nnx, nny) && !d[nx][ny][garo]) {
                d[nx][ny][garo] = d[x][y][garo] + 1;
                q.push({nx,ny,garo});
            }
            //왼
            nx = x;
            nnx = x - 1;
            ny=nny = y - 1;
            if(place(nx,ny, nnx, nny) && !d[nx][ny][garo]) {
                d[nx][ny][garo] = d[x][y][garo] + 1;
                q.push({nx,ny,garo});
            }
            //위
            ny = nny =y;
            nx = x - 1;
            nnx = x - 2;
            if(place(nx,ny, nnx, nny) && !d[nx][ny][garo]) {
                d[nx][ny][garo] = d[x][y][garo] + 1;
                q.push({nx,ny,garo});
            }
            //아래
            nx = x + 1;
            nnx = x;
            if(place(nx,ny, nnx, nny) && !d[nx][ny][garo]) {
                d[nx][ny][garo] = d[x][y][garo] + 1;
                q.push({nx,ny,garo});
            }
            //회전
            if(range(x-1,y-1) && !a[x][y] && !a[x-1][y] && !a[x][y-1]&&!a[x-1][y-1]) {
                if(d[x-1][y-1][1]==0) {
                    d[x-1][y-1][1] = d[x][y][0] + 1;
                    q.push({x-1,y-1,1});
                }
                if(d[x][y-1][1]==0) {
                    d[x][y-1][1] = d[x][y][0] + 1;
                    q.push({x,y-1,1});
                }
            }
            if(range(x-1,y+1) && !a[x][y] && !a[x-1][y] && !a[x][y+1]&&!a[x-1][y+1]) {
                if(d[x-1][y][1]==0) {
                    d[x-1][y][1] = d[x][y][0] + 1;
                    q.push({x-1,y,1});
                }
                if(d[x][y][1]==0) {
                    d[x][y][1] = d[x][y][0] + 1;
                    q.push({x,y,1});
                }
            }
        }
    }
    int ans = 1000000000;
    if(d[n-1][n-1][0]) ans = min(ans, d[n-1][n-1][0]);
    if(d[n-1][n-2][1]) ans = min(ans, d[n-1][n-2][1]);
    if(ans==1000000000) return -1;
    return ans - 1;
}
