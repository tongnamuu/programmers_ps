#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000
int solution(int n, vector<int> weak, vector<int> dist) {
    int k =weak.size();
    vector<int>x(k*2);
    for(int i=0;i<k;++i) {
        x[i] = weak[i];
        x[i+k] = n + weak[i];
    }
    sort(dist.begin(), dist.end());  
    for(int cnt=1;cnt<=dist.size();++cnt) {
        do{
            for(int i=0;i<k;++i) {
                int cur = x[i];
                int end = x[i+k - 1];
                for(int j=dist.size() - cnt;j<dist.size();++j) {
                    cur += dist[j];
                    if(cur >= end) return cnt;                    
                    for(int p = i; p < 2*k;++p) {
                        if(x[p] > cur) {t
                            cur = x[p];
                            break;
                        }
                    }
                }
            }
        }while(next_permutation(dist.end() - cnt, dist.end()));
    }
    return -1;
}
