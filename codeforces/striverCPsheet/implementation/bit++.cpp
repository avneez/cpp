#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;

    string v[n];
    for(int i=0; i<n; i++){
        cin>> v[i];
    }
    int count=0;
    for(int i=0; i<n; i++){
        if(v[i]=="X++" or v[i]=="++X") count+=1;
        else count-=1;
    }
    cout<<count;

return 0;
}