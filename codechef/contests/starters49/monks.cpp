#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    long long arr[n];

	    long long sum=0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
	    }

	    sort(arr,arr+n);
	    int count=0;
	    for(int j=n-1;j>=0;j--){
	        long long avg1 = sum/(j+1);
	        if(arr[j]>avg1) count++;
	        else break;
	    }
	    cout<<count<<endl;
	}
	return 0;
}