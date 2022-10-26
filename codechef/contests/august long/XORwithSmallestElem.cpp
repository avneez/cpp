#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int t; cin>>t;
	while(t--){
	    long long int n,x,y;
	    cin>>n>>x>>y;
	    // long long int arr[n];
		// multiset<long long> arr;
        // multiset<long long> ms;
        // vector<long long> arr(n);


        priority_queue<long long, vector<long long>, greater<long long>> mh;
        // priority_queue<long long, vector<long long>, greater<long long>> mh2;
        long long z;
	    for(long long i=0;i<n;i++){
	        cin>>z;
            mh.push(z);
            // arr.insert(z);
	    }

	    long long k;
		// sort(arr.begin(), arr.end());
		// for(long long i=0;i<y;i++){
		// 	multiset<long long> :: iterator iter;
		// 	iter = arr.begin();
		// 	k = *iter^x;
		// 	// if(k >= (*iter)){
		// 		arr.erase(iter);
		// 		arr.insert(k);
		// 	}

        for(long long i=0; i<y;i++){
            k=mh.top()^x;
            mh.pop();
            mh.push(k);
        }
		while(!mh.empty()){
            cout<<mh.top()<<" ";
            mh.pop();
        }
		cout<<endl;
	}
	return 0;
}