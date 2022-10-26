// C++ Program to split
// a given binary string
// into maximum possible
// segments divisible by
// given odd number K

#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
// Function to calculate
// maximum splits possible

vector<pair<int,string>>dp;
vector<int> cnt;
unordered_map<string,int> mp;
unordered_map<int,int> mp2;

int getd(string bins){
    int number=0;
    number = stoi(bins, 0, 2);
    return number;
}

bool subString(string s, int k)
{
    int n=s.length();
    // Pick starting point in outer loop
    // and lengths of different strings for
    // a given starting point
    // dp.push_back({s[n-1]-'0',s[n-1]});
    for (int i = 0; i < n; i++){
        for (int len = 1; len <= n - i; len++){
            int dec= getd(s.substr(i, len));
            string temp1 = s.substr(i, len);
            dp.push_back({dec,temp1});
            // cout<<s.substr(i, len)<<endl;
            mp[temp1]=dec;
        }
    }
    for(auto it:mp){
        cnt.push_back(it.second);
    }
    for(auto it:cnt){
        mp2[it]++;
    }
    for(auto it:mp2){
        if(it.second==k)
            return true;
    }
    return false;
}



void max_segments(string str, int K)
{
	int n = str.length();
	int s = 0, sum = 0, count = 0;
    int x=n/K;
    string temp;
	for (int i = n - 1; i >= 0; i--) {
		// int a = str[i] - '0';
		// sum += a * pow(2, s);
		// s++;
		// if (sum != 0 && sum % K == 0) {
		// 	count++;
		// 	sum = 0;
		// 	s = 0;
		// }

	}
	// if (sum != 0)
	// 	cout << "-1" << endl;
	// else
	// 	cout << count << endl;
}

// Driver code
int main()
{
	string str = "11011101101";
	int k = 3;
    // dp.resize(str.size());
    // dps.resize(str.size());
	// max_segments(str, k);
    // cout<<getd(str);
    cout<<subString(str,k);

	return 0;
}
