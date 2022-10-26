#include<bits/stdc++.h>
using namespace std;

// //show the most frequent word
// void freq(){
//     vector<string> v= {"ram", "sita", "geeta", "ram", "ram", "sita","ram"};
//     unordered_map<string, int> mp;

//     for(auto it:v){
//         mp[it]++;
//     }
//     pair<string,int> p= {"",INT_MIN};
//     for(auto it:mp){
//         p.second = max(it.second, p.second);
//         p.first = it.first;
//     }
//     cout<<p.first;
// }

// //remove duplicates from a string
// void remDup(){
//     string s="abcdabd";
//     string temp;
//     unordered_set<char> st;
//     for(auto i:s){
//         if(st.find(i)==st.end()){
//             temp+=i;
//         }
//         st.insert(i);
//     }
//     cout<<temp;
// }

// int main(){
//     // freq();
//     remDup();
// return 0;
// }

    vector<int> segregateEvenOddWithOrder(vector<int> arr) {
    int countEven = 0;
    int length = arr.size();
    for (int i = 0; i < length; i++) {
        if (arr[i]%2 == 0){
            countEven++;
        }
    }
    int i = 0;
    int j = i+1;
    while (i != countEven){
        if (arr[i]%2 == 0){
            i++;
            j = i + 1;
        }else if (arr[i]%2 == 1 && j < length){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    return arr;
}

int main(){
    // freq();
    vector<int> arr ={12,98,7,13,4,3};
    segregateEvenOddWithOrder(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }
return 0;
}
