#include <string>
#include <vector>

using namespace std;
int dist(int num, int pos){
    if(num==2){
        if(pos==1||pos==3) return 1;
        else if(pos==4||pos==6) return 2;
        else if(pos==7||pos==9) return 3;
        else if(pos==2) return 0;
        else if(pos==5) return 1;
        else if(pos==8) return 2;
        else if(pos==0) return 3;
        else if(pos==-1) return 5;
    }
    if(num==5){
        if(pos==1||pos==3) return 2;
        else if(pos==4||pos==6) return 1;
        else if(pos==7||pos==9) return 2;
        else if(pos==2) return 1;
        else if(pos==5) return 0;
        else if(pos==8) return 1;
        else if(pos==0) return 2;
        else if(pos==-1) return 3;
    }
    if(num==8){
        if(pos==1||pos==3) return 3;
        else if(pos==4||pos==6) return 2;
        else if(pos==7||pos==9) return 1;
        else if(pos==2) return 2;
        else if(pos==5) return 1;
        else if(pos==8) return 0;
        else if(pos==0) return 1;
        else if(pos==-1) return 2;
    }
    if(num==0){
        if(pos==1||pos==3) return 4;
        else if(pos==4||pos==6) return 3;
        else if(pos==7||pos==9) return 2;
        else if(pos==2) return 3;
        else if(pos==5) return 2;
        else if(pos==8) return 1;
        else if(pos==0) return 0;
        else if(pos==-1) return 1;
    }
}
string solution(vector<int> numbers, string hand) {
    bool r = (hand=="right");
    int lpos=-1,rpos=-1;
    string ans;
    for(int num:numbers){
        if(num==1||num==4||num==7){
            lpos=num;
            ans+='L';
        }
        else if(num==3||num==6||num==9){
            rpos=num;
            ans+='R';
        }
        else{
            int d1=dist(num,lpos);
            int d2=dist(num,rpos);
            if(d1==d2){
                if(r) {
                    rpos=num;
                    ans+='R';
                }
                else {
                    lpos=num;
                    ans+='L';
                }
            }
            else if(d1>d2){
                rpos=num;
                ans+='R';
            }
            else{
                lpos=num;
                ans+='L';
            }
        }
    }
    return ans;
}
