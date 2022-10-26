#include <bits/stdc++.h>
using namespace std;

bool solve(long long x){
    int k = pow(x,0.5);
	for(long long i=1;i<k;i++){
	    if((x-2*i)%(i+2)==0 && x!= 2*i)
	        return true;
	    }
    return false;
}

int main() {
	// your code goes here
	int t; cin>>t;
	long long x;
	while(t--){
	    cin>>x;
	    if(solve(x)) cout<<"YES";
	    else cout<<"NO";
	    cout<<endl;
	}
	return 0;
}
