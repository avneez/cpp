#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i;
    cin>>n;
    bool f=true;
    while(n--){
        cin>>i;
        if(i==1){
            cout<<"hard";
            f=false;
            if(f==false) return 0;
        }
    }
        cout<<"Easy";
return 0;
}

// void solve(int arr[],int n){
//     for(int i=0;i<n;i++){
//         if(arr[i]==1){
//             cout<<"HARD";
//             return;
//         }
//     }
//     cout<<"EASY";
// }

// int main(){
//     int n; cin>>n;
//     int arr[n];
//     int flag=0;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     solve(arr,n);
// return 0;
// }