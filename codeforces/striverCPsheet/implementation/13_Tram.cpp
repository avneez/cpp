#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int a[n], b[n];
    for(int i=0; i<n; i++){
        cin>> a[i] >> b[i];
    }

    int remn=0; int esum=b[0];
    int cap=b[0];
    for(int i=0; i<n-1; i++){
        remn = esum - a[i+1];
        esum = remn + b[i+1];
        cap = max(cap,esum);
    }
cout<<cap;
return 0;
}
