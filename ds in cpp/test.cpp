#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> code(string s)
{
    stringstream ss(s);
    string word;
    vector<string> v;
    while (ss >> word) {
        v.push_back(word);
    }
    
    unordered_map<string, int> mp;
    
    for(int i=0; i<v.size(); i++)
    {
        mp[v[i]]++;
    }
    
    vector<string> str;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second > 1)
        {
            str.push_back(it->first);
            it->second = 1;
        }
    }
    
    sort(str.begin(), str.end());
    
    return str;
}

int main()
{
    string str = "hello hello jh hdh hdg hdg";
    
    vector<string> v = code(str);
    
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}