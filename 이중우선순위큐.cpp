#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int>ms;
    for(string& op : operations){
        if(op[0]=='I'){
            int len = op.length();
            int s = 2;
            if(op[s]=='-') s = 3;
            int val = 0;
            for(int i=s;i<len;++i){
                val*=10;
                val += op[i]-'0';
            }
            if(s==3) val = -val;
            ms.insert(val);
        }
        else if(op[0]=='D'){
            if(ms.empty()) continue;
            if(op[2]!='-'){
                auto it = --ms.end();
                ms.erase(it);
            }
            else{
                ms.erase(ms.begin());
            }
        }
    }
    vector<int> ans;
    if(!ms.empty()){
        auto it = --ms.end();
        int x = *it;
        ans.push_back(x);
        x = *ms.begin();
        ans.push_back(x);
    }
    else{
        ans.push_back(0);
        ans.push_back(0);
    }
    return ans;
}
