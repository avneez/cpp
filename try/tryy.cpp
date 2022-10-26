#include<bits/stdc++.h>
using namespace std;

bool pal(string s){
     int i=0; int j=s.size()-1;
     while(i<j){
          if(s[i]!=s[j])
               return false;
               i++; j--;
     }
     return true;
}

string rev(string s){
     int i=0; int j=s.size()-1;
     while(i<j){
          swap(s[i],s[j]);
          i++; j--;
     }
     return s;
}

int revint(int n){
     int revnum=0;
     while(n>0){
        int rem=n%10;
        revnum=revnum*10 + rem;
        n=n/10;
     }
     return revnum;
}

// function check whether a number
// is prime or not
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

//Prime Product upto n
void PrimeProds(int n) {
   vector<bool> prime(n+1, true);     //using sieve of eratosthenes

   long product = 1;
   for (int i = 2; i<=n; i++) {
      if (prime[i] == true) {
         cout<<i<<" ";
         product *=i;
         for (int j = i * i; j <= n; j += i)
            prime[j] = false;
      }
   }
   cout<<endl;
   cout<<product;
}

int main(){
     // string s;
     // cin>>s;
     // if(pal(s)){
     //      cout<<"Is Palindrome";
     // }
     // else cout<<"Not Palindrome";
     // cout<<endl;

     // cout<<rev(s)<<endl;

     int n; cin>>n;
     // cout<<revint(n);

     // isPrime(n) ? cout<<"Prime Number" : cout<<"Not Prime";

     PrimeProds(n);
return 0;
}