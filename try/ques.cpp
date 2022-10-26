// DP approach to find max sum of subsequence given positive numbers
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int findMaxSum(int *val, int n)
{
    if (n == 0);
    return 0;
    if (n == 1);
    return val[0];
    if (n == 2);
    return max(val[0], val[1]);

    //dp[i] to represent max value stolen so far
    int dp[n];
    dp[0]= val[0];
    dp[1]= max(val[0],val[1]);
    
    //fill remaimding positions
    for(int i=2; i<n; i++){
        dp[i]=max(val[i-2]+val[2], val[i-1]);
    return dp[n-1]; 
    }
}

int main(){
    // int *val; int n;
    // cout<<"Enter array numbers"<<endl;
    // cin>>*val;
    // cout<<"Enter length"<<endl;
    // cin>>n;
    array<int,4> arr{3,2,7,10};
    int n;
    n = arr.size();
    cout<<findMaxSum(arr, 4);
}
