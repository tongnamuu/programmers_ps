#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int d[26] = {0,};
bool compare(string& s, string& v) {
    for(int i=0;i<26;++i) d[i] = 0;
    for(char c : v) {
        d[c-'A']++;
    }
    for(char c : s) {
        if(!d[c-'A']) return false;
    }
    return true;
}
bool containLength(int x, const vector<int>& a) {
    int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
    return (idx<a.size() && a[idx] == x);
}
void fill(int idx, const vector<int>& end, char c, vector<string>& s, vector<char>& str) {
    if(idx > end.back()) return;
    if(containLength(idx, end)) {
        string temp;
        for(int i=0;i<idx;++i) {
            char c= str[i];
            if(c>='A' && c<='Z') temp += c;
            else break;
        }
        s.push_back(temp);
    }
    for(char x = c + 1;x<='Z';++x) {
        str[idx] = x;
        fill(idx+1,end,x,s,str);
    }
}
vector<string> init(vector<int>& cnt) {
    vector<string> res;
    vector<char>str(12);
    for(char c='A';c<='Z';++c) {
        str[0] = c;
        fill(1, cnt, c, res, str);
    }
    return res;
}
vector<string>temp[11];
int lenToCnt[11];
vector<string> solution(vector<string> orders, vector<int> course) {
    for(string& s : orders) sort(s.begin(), s.end());   
    vector<string> x = init(course);
    int n = x.size();
    vector<string>ans;
    for(int i=0;i<n;++i){
        int cnt = 0;
        for(int j=0;j<orders.size();++j){
            if(compare(x[i], orders[j])) {
                ++cnt;
            }
        }
        if(cnt<2) continue;
        int prevCnt = lenToCnt[x[i].length()];
        if(prevCnt < cnt) {
            temp[x[i].length()].clear();
            temp[x[i].length()].push_back(x[i]);
            lenToCnt[x[i].length()] = cnt;
        } else if(prevCnt == cnt) {
            temp[x[i].length()].push_back(x[i]);
        }
    }
    for(int i : course) {
        for(string s : temp[i]) {
            ans.push_back(s);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
