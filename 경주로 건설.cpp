#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
long long d[26][26][4];
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};
struct Edge{
    int x, y, c, dir;
    bool operator<(const Edge& a) const{
        return c>a.c;
    }
};
int solution(vector<vector<int>> board) {
    int n =board.size();
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<4;++k){
                d[i][j][k]=1000000000;
            }
        }
    }
    priority_queue<Edge>q;
    q.push({0,0,0,1});
    q.push({0,0,0,3});
    d[0][0][1]=0;
    d[0][0][3]=0;
    while(!q.empty()){
        int x=q.top().x;
        int y=q.top().y;
        int prev=q.top().dir;
        int c=q.top().c;
        q.pop();
        for(int dir=0;dir<4;++dir){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(!(nx>=0&&nx<n&&ny>=0&&ny<n)) continue;
            if(board[nx][ny]==1) continue;
            int nc=100;
            if(dir!=prev)nc+=500;
            if(d[nx][ny][dir]>nc+c){
                d[nx][ny][dir]=nc+c;
                q.push({nx,ny,nc+c,dir});
            }
        }
    }
    int answer = min({d[n-1][n-1][0],d[n-1][n-1][1],d[n-1][n-1][2],d[n-1][n-1][3]});
    return answer;
}
