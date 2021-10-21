#include <iostream>
#include <vector>
using namespace std;

int partition(vector <int> &arr, int low, int high)
{
    int pivot = high, pindex = low, i;

    for (i = low; i < high; i++)
    {
        if (arr[i] <= arr[pivot])
        {
            swap(arr[i], arr[pindex]);
            pindex++;
        }
    }
    swap(arr[pivot], arr[pindex]);
    return pindex;
}

void quickSort(vector <int> &arr, int low, int high)
{
    int pindex;
    if (low < high)
    {
        pindex = partition(arr, low, high);
        quickSort(arr, low, pindex-1);
        quickSort(arr, pindex+1, high);
    }
}

int main()
{
    vector <int> arr;
    int a, size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {   
        cin >> a;
        arr.push_back(a);
    }

    quickSort(arr, 0, size-1);
    cout << "Sorted Data:\n";

    for (int i : arr) // i = 0; i < arr.size(); i++ and cout arr
        cout << i << " ";
    
    return 0;
}