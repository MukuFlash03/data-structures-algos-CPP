#include <bits/stdc++.h>
using namespace std;

int merge(int* arr, int n, int low, int mid, int high)
{
    int i = low, j = mid+1, k = 0;
    int temp[high-low+1];

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    
    while (j <= high)
        temp[k++] = arr[j++];

    for(i = low; i <= high; i++)
        arr[i] = temp[i-low];
}

void mergeSort(int* arr, int n, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low+high)/2;
        mergeSort(arr,n,low,mid);
        mergeSort(arr,n,mid+1,high);
        merge(arr,n,low,mid,high);
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
    mergeSort(arr,n,low,high);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}