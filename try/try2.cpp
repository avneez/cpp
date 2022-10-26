#include<bits/stdc++.h>
using namespace std;

// int summ(int num){
//     int s=0;
//     while(num>0){
//         int rem= num%10;
//         num=num/10;
//         s+=rem;
//     }
//     return s;
// }

// vector<int> prodDelivery (vector<int>& orderID){
//     vector<int> ans;
//     for(int i=0; i<orderID.size(); i++){
//         int x = summ(orderID[i]);
//         ans.push_back(x);
//     }
//     return ans;
// }


// int main(){
//     vector<int> ans;
//     vector<int> orderID = {43, 345, 20};
//     ans=prodDelivery(orderID);
//     for(int i=0; i<orderID.size(); i++){
//         cout<<ans[i]<<" ";
//     }
// return 0;
// }

bool compare(pair<int,int> p1, pair<int,int> p2)
{
 if(p1.second==p2.second){
        return p1.first<p2.first; //return the smaller value first i.e., in increasing order
    }
    return p1.second>p2.second;   //else returns the bigger value according to the highest frequency of elements
}

vector<int> freqSort(vector<int> arr){
    int n=arr.size();
    map<int,int>m;

    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    vector<pair<int,int>> a;

    for(auto it:m){
       a.push_back({it.first,it.second});
    }

    sort(a.begin(),a.end(),compare);

    vector<int>ans;

    for(auto x:a){
        while(x.second--){
          ans.push_back(x.first);
        }
    }
    return ans;
}

int main(){
    vector<int> ans;
    vector<int> arr = {1,2,2,3,3,3,4,4,5,5,5,5,6,6,6,7,8,9,10};
    ans = freqSort(arr);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
