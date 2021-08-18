#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
int visit[51][51];
void dfs(int x, int y, vector<vector<int>>& a, vector<pair<int,int>>& res, int val) {
    visit[x][y] = 1;
    res.push_back({x,y});
    for(int dir=0;dir<4;++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx>=0&&nx<a.size() && ny>=0&&ny<a[0].size() && !visit[nx][ny] && a[nx][ny] == val) {
            dfs(nx,ny, a, res, val);
        }
    }
}
int map[6][6];
int temp[6][6];
void init_map(){
    for(int i=0;i<6;++i) for(int j=0;j<6;++j) map[i][j] = 0;
}
void point_to_map(vector<pair<int, int>>& p){
    int minx = 10000, miny = 10000;
    for(auto& x : p) {
        if(minx>x.first) minx =x.first;
        if(miny>x.second) miny = x.second;
    }
    for(auto& x:p) {
        map[x.first - minx][x.second-miny] = 1;
    }
}
void rotate() {
    for(int i=0;i<6;++i){
        for(int j=0;j<6;++j){
            temp[j][5-i] = map[i][j];
            map[i][j] = 0;
        }
    }
    int minx = 10000, miny = 10000;
    vector<pair<int, int>> pos;
    for(int i=0;i<6;++i){
        for(int j=0;j<6;++j){
            if(temp[i][j]){
                minx=min(minx, i);
                miny=min(miny, j);
                pos.push_back({i,j});
            }
        }
    }
    for(auto& x:pos) {
        map[x.first - minx][x.second-miny] = 1;
    }
}
long long make_num() {
    long long num = 0;
    for(int i=0;i<6;++i){
        for(int j=0;j<6;++j){
            num <<= 1;
            if(map[i][j]) num |= 1;
        }
    }
    return num;
}
vector<long long> get_blanks(vector<vector<int>>& a) {
    vector<pair<int, int>> result;
    int n = a.size();
    vector<long long> blanks;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(a[i][j]==0 && visit[i][j]==0) {
                result.clear();
                dfs(i,j,a, result, 0);
                point_to_map(result);
                long long x = make_num();
                blanks.push_back(x);
                init_map();
            }
        }
    }
    return blanks;
}
vector<vector<long long>> get_blocks(vector<vector<int>>& a) {
    int n = a.size();
    vector<pair<int, int>> result;
    vector<vector<long long>>ans;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)visit[i][j] = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(a[i][j]==1 && visit[i][j]==0) {
                vector<long long> temp;
                result.clear();
                dfs(i,j,a, result, 1);
                point_to_map(result);
                for(int k=0;k<4;++k){
                    long long x = make_num();
                    temp.push_back(x);
                    rotate();
                }
                init_map();
                ans.push_back(temp);                    
            }
        }
    }
    return ans;
}
int count_bits(long long val){
    int ans = 0;
    while(val){
       if(val&1) ++ans;
       val >>= 1;
    }
    return ans;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    vector<long long> board = get_blanks(game_board);
    vector<vector<long long>> blocks = get_blocks(table);
    vector<int>check(blocks.size());
    int ans = 0;
    for(long long x : board) {
        for(int i=0;i<blocks.size();++i){
            if(check[i]) continue;
            for(long long y:blocks[i]) {
                if(x==y) {
                    ans += count_bits(x);
                    check[i] = 1;
                    i = blocks.size();
                    break;
                }
            }
        }
    }
    return ans;
}
