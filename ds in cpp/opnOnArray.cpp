#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

// int factorial(int n)
// {
//     if (n == 1)
//         return 1;

//     int k;
//     k = n * factorial(n - 1);
//     return k;
// }

// int main()
// {
//     int n;
//     cout<<"Input number: ";
//     cin>>n;
//     cout << "Factorial is: "<<factorial(n);
// }

int maxSum(int arr[], int n, int k)
{
    int i, j = 0;
    int sum = 0;
    vector<int> v;

    while (j < n)
    {
        if (j - i + 1 < k)
        {   sum = sum + arr[j];
            j++;
        }
        else if (j - i + 1 == k)
        {
            sum = sum + arr[j];
            v.push_back(sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    return *max_element(v.begin(), v.end());
}

int main()
{
    int arr[] = {2, 1, 0, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<maxSum(arr, n, 2) << endl;
    cout<<"Hello";
    return 0;
}