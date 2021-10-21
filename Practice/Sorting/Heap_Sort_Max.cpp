#include <bits/stdc++.h>
using namespace std;


void maxHeapify(int* arr, int n, int i)
{
    int largest = i;
    int lc = 2*i + 1;
    int rc = 2*i + 2;

    if (lc < n && arr[lc] > arr[largest])
        largest = lc;
    if (rc < n && arr[rc] > arr[largest])
        largest = rc;

    if (largest != i)
    {
        swap(arr[i],arr[largest]);
        maxHeapify(arr,n,largest);
    }
}

void heapSort(int* arr, int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr,n,i);

    for (int i = n-1; i > 0; i--)
    {
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr,n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}