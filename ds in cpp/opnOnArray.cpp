#include <iostream>
#include <cctype>
using namespace std;

void search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            cout << "Element position is " << i + 1 << endl;
    }
}

void insert(int arr[], int pos, int cap, int x, int n)
{
    cap = 50;
    if (n == cap)
    {
        cout << "Size is full" << endl;
    }
    int idx = pos - 1;
    for (int i = n - 1; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[idx] = x;
    // return (n + 1);
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << "  ";
    }
}

int getLargest(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[res])
        {
            res = i;
        }
    }
    return res;
}

int main()
{
    int n;
    // int x;
    int arr[50];

    cout << "Enter the length of array between 1 to 50" << endl;
    cin >> n;
    // n = sizeof(arr)/sizeof(arr[0]);
    if (n <= 50)
    {
        cout << "Enter the elements" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    else
    {
        cout << "Invalid Size"<<endl;
        return -1;
    }
    int user;
    cout << "Enter the element to search" << endl;
    cin >> user;
    cout << endl;
    search(arr, n, user);
    char ans;
    int pos, data;
    cout << "Do you want to insert element [Y/N]";
    cin >> ans;
    ans = toupper(ans);
    if (ans == 'Y')
    {
        cout << "Enter the position to insert the element: ";
        cin >> pos;
        cout << "Enter the data to insert in the element: ";
        cin >> data;
        insert(arr, pos, 50, data, n);
        n = n + 1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << "  ";
        }
    }
    cout << endl;
    cout << "Largest element is at position: " << getLargest(arr, n) + 1 << endl;
    cout << "Largest element is: " << arr[getLargest(arr, n)];
}
//deletion