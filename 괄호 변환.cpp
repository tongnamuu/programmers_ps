#include <string>
#include <vector>

using namespace std;

bool check(const string& s) {
    int val = 0;
    for(char c:s) {
        if(c=='(') val++;
        else val--;
        if(val<0) return false;
    }
    return val == 0;
}
string solve(const string& s) {
    int n = s.length();
    if(n==0 || check(s)) return s;
    int val = 0;
    int idx = 0;
    for(int i=0;i<n;++i) {
        if(s[i]=='(') val++;
        else val--;
        if(val==0) {
            idx=i;break;
        }
    }
    string u = s.substr(0, idx + 1);
    string v = s.substr(idx + 1, n - idx - 1);
    if(!check(u)) {
        string temp = "(";
        temp += solve(v);
        temp += ')';
        for(int i=1;i<u.size() - 1;++i){
            if(u[i]=='(') temp += ')';
            else temp += '(';
        }
        return temp;
    }
    return u + solve(v);
}
string solution(string p) {
    return solve(p);
}
