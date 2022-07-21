/* Disjoint Set Union..........
    n sets, lets say n=3

    set 1 = 1(R) //R is parent
    now, set 1,2 = 1(R), 2 after union_set(1,2)

    set 2 = 2(R)
    aet 3 = 3(R)

    union_set(1,2);
    par[2]=1;
    1(R),2
    2->1(R)

    union_set(2,3);
    par[3]=par[2]=1; 3->1<-2
    1(R),2,3
*/

#include<bits/stdc++.h>
using namespace std;

void make_set(int num, int par){
    par[num]=num;
}

int find_set(int a, int par){
    if(par[a]==a) return a;
    return find_set(par[a],par);
}

void union_set(int a, int b, int par){
    a=find_set(a,par);
    b=find_set(b,par);
    if(a==b){
        cout<<"No Union Set"<<endl;
        return;
    }
    par[b]=a;
}


int main(){
    freopen("input.txt","r", stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    vector<int> par(n+1);
    for(int i=1;i<=n; i++){
        make_set(i,par);
    }
    int a,b;
    cin>>a>>b;
    union_set(a,b,par);
}