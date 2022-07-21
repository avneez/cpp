#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum=0;
    string v[n];
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i]=="Tetrahedron") sum+=4;
        else if(v[i]=="Cube") sum+=6;
        else if(v[i]=="Octahedron") sum+=8;
        else if(v[i]=="Dodecahedron") sum+=12;
        else if(v[i]=="Icosahedron") sum+=20;
    }
    cout<<sum;
return 0;
}
