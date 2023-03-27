#include <bits/stdc++.h>
using namespace std;

int partition(int* arr, int n, int low, int high)
{
    int pivot = high, pindex = low;

    for (int i = low; i < high; i++)
        if (arr[i] <= arr[pivot])
            swap(arr[i],arr[pindex++]);

    swap(arr[pivot],arr[pindex]);
    return pindex;
}

void quickSort(int* arr, int n, int low, int high)
{
    int pindex;

    if (low < high)
    {
        pindex = partition(arr,n,low,high);
        quickSort(arr,n,low,pindex-1);
        quickSort(arr,n,pindex+1,high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int low = 0, high = n-1;
    quickSort(arr,n,low,high);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}