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
long PrimeProds(int n) {
   bool prime[n + 1];
   for(int i = 0; i<=n; i++){
      prime[i] = true;
   }
   for (int i = 2; i * i <= n; i++) {
      if (prime[i] == true) {
         for (int j = i * 2; j <= n; j += i)
            prime[j] = false;
      }
   }
   long product = 1;
   for (int i = 2; i <= n; i++)
      if (prime[i])
      product *= i;
   return product;
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

     cout<<PrimeProds(n);
return 0;
}