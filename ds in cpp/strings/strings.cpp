// C++ program to create a unique string using unordered_map

/* access time in unordered_map on is O(1) generally if no collisions occur
and therefore it helps us check if an element exists in a string in O(1)
time complexity with constant space. */

#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s,int n){
unordered_map<char,int> exists;
string temp;
for(int i=0;i<n;i++){
	if(exists[s[i]]==0)
	{
	temp += s[i];
	exists[s[i]]++;
	}
}
return temp;
}

string decode(string s){
    // string temp;
    // for(int i=0; i<s.size(); i=i+2){
    //     for(int j=0; j<s[i+1]-'0'; j++){
    //         temp+=s[i];
    //     }
    // }
    // return temp;

    char c = ' ';
    string ans = "";
    int i = 0;
    while(i<s.size()){
        c = s[i++];
        int n = 0;
        while(s[i] >= '0' and s[i] <= '9'){
            n = n*10 + (s[i]-'0');
            i++;
        }
        ans+=string(n,c);
    }
    return ans;
}

string compression(string s){
    char c = ' ';
    int i = 0;
    string ans="";
    while(i<s.size()){
        int c_n = 0;
        c = s[i];
        while(s[i] == c){
            c_n++;
            i++;
        }
        ans += c;
        ans += c_n+'0';
    }
    return ans;
}


//driver code
int main(){
    // string s= "geeksforgeeks";
    string t= "a3b4c2";
    string t2 = "aaabbbbcc";
    // int n = s.size();
    // cout<<removeDuplicates(s,n)<<endl;
    cout<<decode(t)<<endl;
    cout<<compression(t2);

return 0;
}
