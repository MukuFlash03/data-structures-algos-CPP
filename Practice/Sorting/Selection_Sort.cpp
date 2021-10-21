#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int pos = 0;

    for (int i = 0; i < n-1; i++)
    {
        pos = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[pos])
                pos = j;
        }

        swap(arr[pos],arr[i]);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}