#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>>a(n+1, vector<int>(n+1));
    for(auto& r : results){
        a[r[0]][r[1]] = 1;
        a[r[1]][r[0]] = -1;
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(a[i][k]==1 && a[k][j]==1){
                    a[i][j] = 1;
                    a[j][i] = -1;
                }
                if(a[i][k]==-1 && a[k][j]==-1){
                    a[i][j] = -1;
                    a[j][i] = 1;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;++i){
        int cnt = 0;
        for(int j=1;j<=n;++j){
            if(a[i][j]) cnt++;
        }
        if(cnt==n-1) ans++;
    }
    return ans;
}
