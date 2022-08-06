#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string temp;
    for(auto ch:s){
        if(ch!='+')
            temp+=ch;
        else ch++;
    }

    sort(temp.begin(), temp.end());

    string t; int j=0;
    for(int i=0; i<s.size(); i++){
        if(i%2==0){
            t+=temp[j];
            j++;
        }
        else t+='+';
    }
    cout<<t;
return 0;
}