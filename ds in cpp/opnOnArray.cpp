// C++ implementation to count
// subarrays having sum
// as a perfect cube

#include <bits/stdc++.h>
using namespace std;
#define int long long

// Function to check for
// perfect cube or not
bool isCubicSquare(int x)
{
	int curoot = round(pow(x, 1.0 / 3.0));

	if (curoot * curoot * curoot == x)
		return true;
	return false;
}

// Function to count the subarray
// whose sum is a perfect cube
int count(int arr[], int n)
{
	int pre[n + 1];

	pre[0] = 0;

	// Loop to find the prefix sum
	// of the array
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + arr[i - 1];
	}

	int ans = 0;

	// Loop to take every
	// possible subarrays
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {

			// check for every
			// possible subarrays
			if (isCubicSquare((double)(pre[j] - pre[i]))) {
				ans++;
			}
		}
	}

	return ans;
}

// Driver Code
int main(){
	int arr[6] = { 6, 2 };

	int ans=count(arr, 2);

	return ans;
}
