#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int temp = arr[0];
    int j = 1;
    bool flag;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != temp)
        {
            temp = arr[i];
            swap(arr[i],arr[j]);
            j++;
        }
        else
            flag = true;
    }

    if (flag)
        cout << "Duplicates exist" << endl;
    else
        cout << "Duplicates don't exist" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}