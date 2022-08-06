#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (long long i = a; i < b; i++)
#define rf(i, a, b) for (long long i = a; i >= b; i--)
#define ll long long
#define mp make_pair
#define pb push_back
#define vll vector<long long>
#define vvl vector<vll>
#define pll pair<ll, ll>
#define vc vector
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int main()
{
    int sup;
    cin >> sup;
    while (sup--)
    {
        ll n, x, y; cin >> n >> x >> y;vll a(n);
        f(i, 0, n){
                cin >>a[i];} ll scarlet = 0;
        if (x <= y)
        {
            ll witch = *max_element(all(a));
            if (witch <= 0){
                cout << 0 << endl;}
            else{
                cout << Ceil(witch, y) << endl;}
        }
        else
        {
            f(i, 0, n)
                {a[i] = max(a[i], 0ll);}
            ll raja = 0;
            rf(i, n - 1, 0)
            {
                a[i] -= raja;
                a[i] = max(a[i], 0ll);
                ll akbar = Ceil(a[i], x);
                raja += y * akbar;
                scarlet += akbar;
            }cout << scarlet << endl;
        }
    }
    return 0;
}