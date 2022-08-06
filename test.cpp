#include <bits/stdc++.h>
using namespace std;

// // class Base{
// //     public:
// //     virtual void show() { cout<<" In Base \n";}
// // };

// // class Derived: public Base{
// //     public:
// //     void show() { cout<<" In Derived \n";}
// // };

// // int main(void){
// //     // Base *bp = new Derived;
// //     // bp->show();

// //     // Base &br = *bp;
// //     // br.show();

// //     Base *bp, b;
// //     Derived d;
// //     bp = &d;
// //     bp->show();

// //     bp = &b;
// //     bp->show();

// //     return 0;
// // }

// // class Base{};
// // class Derived: public Base{};
// // int main(){
// //     Derived d;
// //     try {
// //         throw d;
// //     }
// //     catch(Base b){
// //         cout<<"Caught Base Exception";
// //     }
// //     catch(Derived d){
// //         cout<<"Caught Derived Exception";
// //     }
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll bs1(ll l, ll h, ll x, vector<ll> a[], ll k)
// {
//     if(l<=h)
//     {
//         ll m=(l+h)/2;

//         if(a[x][m]>=k)
//         {
//             if(m==l){
//                 return m;
//             }else if(a[x][m-1]<k){
//                 return m;
//             }else{
//                 return bs1(l, m-1, x, a, k);
//             }
//         }else{
//             return bs1(m+1, h, x, a, k);
//         }
//     }else{
//         return -1;
//     }
// }
// ll bs2(ll l, ll h, ll x, vector<ll> a[], ll k)
// {
//     if(l<=h)
//     {
//         ll m=(l+h)/2;

//         if(a[x][m]<=k)
//         {
//             if(m==h){
//                 return m;
//             }else if(a[x][m+1]>k){
//                 return m;
//             }else{
//                 return bs2(m+1, h, x, a, k);
//             }
//         }else{
//             return bs2(l, m-1, x, a, k);
//         }
//     }else{
//         return -1;
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     ll n, q, i, j, r, l, l1, r1, x, b, s;

//     cin>>n;

//     vector<ll> a[n+1];

//     for(i=1; i<=n; i++)
//     {
//         cin>>b;
//         a[b].push_back(i);
//     }

//     cin>>q;

//     for(;q--;)
//     {
//         cin>>l>>r>>x;

//         s=a[x].size();

//         l1=bs1(0, s-1, x, a, l);
//         r1=bs2(0, s-1, x, a, r);

//         if(l1==-1)
//         {
//             cout<<"0\n";
//         }else{
//             cout<<r1-l1+1<<"\n";
//         }
//     }
// }

int main(){
    cout<<max('a','b');
    return 0;
}