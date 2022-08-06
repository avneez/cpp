#include <bits/stdc++.h>
using namespace std;

bool prime(int y)
{
    for(int i=2;i<=y/2;i++)
    {
        if(y%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // cout<<"Hello World";
    cout<<"enter the number ";
    long long x = 1e9;
    // cin>>x;
    int y; cin>>y;
    int count=0;
    for(int i=2;i<=x;i++)
    {
        if(prime(i))
        {
            if(count!=y)
            {
            cout<<i<<"\n";
            count++;
            }
            if(count==y)
            break;
        }

    }
   return 0;
}