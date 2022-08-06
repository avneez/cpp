#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    int k,w;
    long long total=0;
    cin>>k>>n>>w;

    for(int i=1; i<=w; i++){
        total+=k*i;
    }
    if(n<total)
        cout<<total-n;
    else cout<<0;
return 0;
}