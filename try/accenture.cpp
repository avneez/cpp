// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//   string s;
//   getline(cin, s);
//   vector<string> temp;
//   int i = 0;
//   int j = 1;
//   for (i=0; i<s.size(); i++)
//   {
//     string tmp;
//     if (s[i] == ' ')
//     {
//       tmp = s.substr(i, j);
//       reverse(tmp.begin(), tmp.end());
//       temp.push_back(tmp);
//       j=0;
//     }
//     j++;
//   }
//   for(int i=0; i<temp.size(); i++){
//     cout<<temp[i]<<" ";
//   }
//   return 0;
// }

// void reverseWords(string s){
//     vector<string> tmp;
//     string str = "";
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == ' ')
//         {
//             tmp.push_back(str);
//             str = "";
//         }
//         else
//             str += s[i];
//     }
//     tmp.push_back(str);
//     int i;
//     // string temp;

//     // reverse(tmp.begin(), tmp.end());
//      for (i = tmp.size() - 1; i > 0; i--)
//         cout << tmp[i] << " ";
//     cout << tmp[0] << endl;

// }

// int main()
// {
//   string s;
//   getline(cin, s);
//   reverseWords(s);
// }

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);

    vector<string> temp ;
    string str="";
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]==' '){
            temp.push_back(str);
            str="";
        }
        else{
            str+=s[i];
        }
    }
    if(str!=""){
        temp.push_back(str);
    }
    vector<string>op;
    for(string str:temp){
        string str2=str;
        reverse(str2.begin(),str2.end());
        op.push_back(str2);
    }
    for(string str:op){
        cout<<str<<" ";
    }
    cout<<endl;
    return 0;
}