#include <string>
#include <vector>

using namespace std;
int map[60][60];
vector<vector<int>>keys[4];
void init(vector<vector<int>>& lock) {
    int n = lock.size();
    for(int i=20;i<n+20;++i){
        for(int j=20;j<n+20;++j){
            map[i][j] = lock[i-20][j-20];
        }
    }
}
bool check(vector<vector<int>>& lock) {
    int n = lock.size();
    for(int i=20;i<n+20;++i){
        for(int j=20;j<n+20;++j){
            if(!map[i][j]) return false;
        }
    }
    return true;
}
bool range(int n, int x, int y) {
    return x>=20 && x<20+n && y>=20&&y<20+n;
}
vector<vector<int>> rotate(vector<vector<int>>& key) {
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>>rotateKey(m, vector<int>(n));
    for(int j=0;j<m;++j) {
        for(int i=0;i<n;++i) {
            rotateKey[j][i] = key[n - i - 1][j];
        }
    }
    return rotateKey;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    for(int r=0;r<4;++r) {
        keys[r] = key;
        key = rotate(key);
    }
    for(int x=0;x<60;++x){
        for(int y=0;y<60;++y) {
            for(int r=0;r<4;++r) {
                init(lock);
                bool okay = true;
                int n = keys[r].size();
                int m = keys[r][0].size();
                for(int i=x;i<n+x;++i){
                    for(int j=y;j<m+y;++j) {
                        if(range(lock.size(), i, j) && keys[r][i-x][j-y]==1) {
                            if(map[i][j]) {
                                okay = false;
                                i = n+x;
                                j = m+y;
                                break;
                            }
                            map[i][j] = 1;
                        }
                    }
                }
                if(okay && check(lock)) return true;
            }
        }
    }
    return false;
}
