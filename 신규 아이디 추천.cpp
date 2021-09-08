#include <string>
#include <vector>

using namespace std;
bool isUpper(char c) {
    return c >= 'A' && c<='Z';
}
bool isLower(char c) {
    return c >= 'a' && c<='z';
}
bool isNum(char c) {
    return c>='0' && c<='9';
}
bool isOp(char c) {
    return c=='-' || c=='_' || c=='.';
}
string solution(string new_id) {
    string temp;
    for(char& c : new_id) {
        if(isUpper(c)) {
            temp += c-'A' + 'a';
        } else if(isLower(c) || isNum(c) || isOp(c)) {
            temp += c;  
        } 
    }
    int n = temp.length();
    string ans;
    bool flag = false;
    for(int i=0;i<n;++i) {
        if(temp[i] == '.') {
            if(!flag){
                flag = true;
                ans += '.';
            } 
        } else {
            ans += temp[i];
            flag = false;
        }
    }
    n = ans.length();
    if(ans[0]=='.' && ans[n - 1] == '.') ans = ans.substr(1, n - 2);
    else if(ans[0]!='.' && ans[n - 1] == '.') ans = ans.substr(0, n - 1);
    else if(ans[0]=='.' && ans[n - 1] != '.') ans = ans.substr(1, n - 1);
    n = ans.length();
    if(n==0) ans += 'a';
    if(n>=16) ans = ans.substr(0, 15);
    while(ans.size() && ans.back()=='.') {
        ans.pop_back();
    }
    while(ans.size()<=2) {
        ans += ans.back();
    }
    return ans;
}
