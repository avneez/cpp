#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int isSubSequence(string& s1, string& s2, int i, int j)
{
	if (i == 0 || j == 0) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (s1[i - 1] == s2[j - 1]) {
		return dp[i][j] = 1 + isSubSequence(s1, s2, i - 1, j - 1);
	}
	else {
		return dp[i][j] = isSubSequence(s1, s2, i, j - 1);
	}
}

int main()
{
	string str1;
	string str2;
    cin>>str1>>str2;
	int m = str1.size();
	int n = str2.size();
	// if (m > n) {
	// 	cout << "NO" << endl;
	// 	return 0;
	// }
	dp[m][n];
    int c=0;
	memset(dp, -1, sizeof(dp));
	if (isSubSequence(str1, str2, m, n) == m) {
        c++;
    }
    cout<<c;
	return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// int countWays(string S1, string S2)
// {
// 	int m = S1.size(), n = S2.size();
// 	vector<int> count(n, 0);

// 	for (int i = 0; i < m; i++)
// 	{
// 		for (int j = n - 1; j >= 0; j--)
// 		{
// 			if (S1[i] == S2[j])
// 			{
// 				count[j] += (j == 0 ? 1 : count[j - 1]);
// 			}
// 		}
// 	}

// 	return count[n - 1];
// }

// int main()
// {
// 	string S1 = "malyalam", S2 = "mam";
// 	cout << countWays(S1, S2) << "\n";
// 	return 0;
// }
