#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    auto start = high_resolution_clock::now();
    int maxi = max(x,(max(y,z)));
    int mini = min(x,(min(y,z)));
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<maxi-mini<<endl;
    cout<<"time taken: "<<duration.count();
return 0;
}