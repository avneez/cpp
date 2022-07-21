#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int a,b,c=0;
    int maxi = *max_element(arr,arr+n);
    int mini = *min_element(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]==maxi){
            a=i;
            break;
        }
    }

    while(a!=0){
        swap(arr[a],arr[a-1]);
        a--;
        c++;
    }

    for(int i=0;i<n;i++){
        if(arr[i]==mini){
            b=i;
        }
    }

    while(b!=(n-1)){
        swap(arr[b],arr[b+1]);
        b++;
        c++;
    }
    cout<<c;
return 0;
}
