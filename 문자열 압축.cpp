#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(string s) {
    int n = s.length();
    int ans = n;
    for(int k=1;k<=n;++k) {
        int i = 0;
        string expr = s.substr(i, k);
        i+=k;
        int temp = 0;
        int cnt = 1;
        while(i<n) {
            string x = s.substr(i, k);
            if(x==expr) {
                cnt++;
            } else {
                if(cnt==1) {
                    temp += expr.length();
                } else {
                    temp += expr.length();
                    while(cnt) {
                        temp++;
                        cnt/=10;
                    }
                }
                expr = x;
                cnt = 1;
            }
            i+=k;
        }
        if(cnt==1) {
            temp += expr.length();
        } else {
            temp += expr.length();
            while(cnt) {
                temp++;
                cnt/=10;
            }
        }
        ans = min(ans, temp);
    }
    return ans;
}
