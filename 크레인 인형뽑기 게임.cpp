#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<int>map[33];
stack<int>ans;
int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size();
    int m = board[0].size();
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<m;++j){
            if(board[i][j]) map[j+1].push(board[i][j]);
        }
    }
    int anwer = 0;
    for(int x : moves) {
        if(!map[x].empty()) {
            if(!ans.empty() && map[x].top() == ans.top()) {
                ans.pop();
                anwer += 2;
            } else {
                ans.push(map[x].top());
            }
            map[x].pop();
        }
    }
    return anwer;
}
