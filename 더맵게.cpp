#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int>q;
    for(int s:scoville){
        q.push(-s);
    }
    int ans = 0;
    while(q.size()>1){
        int x = -q.top();
        if(x>=K) break;
        q.pop();
        int y = - q.top();
        q.pop();
        q.push(-x-2*y);
        ++ans;
    }
    if(-q.top() < K) return -1;
    return ans;
}
