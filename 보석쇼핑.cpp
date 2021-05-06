#include <string>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    int n = gems.size();
    map<string, int>temp;
    for(string& s : gems){
        temp[s]++;
    }
    const int GEM_CNT=temp.size();
    int cnt = 0;
    int i=0,j=0;
    map<string, int>gem;
    gem[gems[0]]=1;
    int l = 0;
    int r= n+1;
    while(i<n&&j<n){
        if(gem.size()==GEM_CNT){
            if(j-i+1<r-l+1){
                if(j-i+1==r-l+1){
                    if(i<l){
                        l=i,r=j;
                    }
                }
                else r=j,l=i;
            }
            if(gem[gems[i]]==1){
                gem.erase(gems[i]);
            }
            else gem[gems[i]]--;
            i++;
        }
        else if(gem.size()<GEM_CNT){
            j++;
            if(j<n) gem[gems[j]]++;   
        }
    }
    vector<int> answer={l+1,r+1};
    return answer;
}
