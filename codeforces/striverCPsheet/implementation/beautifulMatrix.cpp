#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)

int main(){
    int i,j,r,c,grid[6][6];
    rep(i,1,6){
        rep(j,1,6){
            cin>>grid[i][j];
            if(grid[i][j]==1){
                r=abs(3-i);
                c=abs(3-j);
            }
        }
    }
    cout<<r+c;
    return 0;
}