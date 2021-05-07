#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<long long, long long> check;
long long find(long long x) {
    auto m = check.find(x);
    if(m == check.end()) return check[x] = x + 1;
    long long next = m -> second;
    return check[x] = find(next);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> ans;
    for(long long val : room_number) {
       long long res = find(val);
        ans.push_back(res - 1);
    }
    return ans;
}
