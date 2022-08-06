#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    set<char> st;
    cin>>s;
    int c=0;
    for(auto it:s) st.insert(it);
    if(st.size()%2==0) cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";
return 0;
}