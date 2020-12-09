#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int n = numbers.size();
    int ans = 0;
    for(int i=0;i<(1<<n);++i){
        int val = 0;
        for(int j=0;j<n;++j){
            if(i&(1<<j)){
                val += numbers[j];
            }
            else{
                val -= numbers[j];
            }
        }
        if(val==target) ++ans;
    }
    return ans;
}
