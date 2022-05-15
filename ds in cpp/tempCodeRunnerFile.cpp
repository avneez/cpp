
        sum = sum + arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        if (j - i + 1 == k)
        {
            mx = max(mx, sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    return mx;
}

int main()
{
    int arr[] = {1, 5, 8, 3, 5, 2, 1, 0, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<maxSum(arr, n, 3) << endl;
    return 0;