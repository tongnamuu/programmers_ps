#include <string>
#include <vector>

using namespace std;
struct Node {
    int children[10];
    bool end;
};
Node nodePool[1000000];
int nodeCnt = 0;
int newNode() {
    for(int i=0;i<10;++i) nodePool[nodeCnt].children[i] = -1;
    nodePool[nodeCnt].end = false;
    return nodeCnt++;
}
bool insert(int node, int idx, const string& s, bool allin, bool result) {
    if(nodePool[node].end && allin) {
        return true;
    }
    if(idx == s.length()) {
        nodePool[node].end = true;
        if(result || allin) return true;
        return false;
    }
    int& next = nodePool[node].children[s[idx]-'0'];
    if(next==-1) {
        next = newNode();
        allin = false;
    }
    return insert(next, idx+1, s, allin, result);
}
bool solution(vector<string> phone_book) {
    int node = newNode();
    for(string& s : phone_book) {
        if(insert(node, 0, s, true, false)) return false;
    }
    return true;
}
