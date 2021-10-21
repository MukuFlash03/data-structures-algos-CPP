#include <bits/stdc++.h>
using namespace std;
 
int partition (vector <int> &arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = low;        // Index of smaller element
    for (int j = low; j < high; j++)
    {
        /* 
          If current element is smaller than or
          equal to pivot
        */
        if (arr[j] <= pivot)
        {    
            swap(arr[i], arr[j]);          // increment index of smaller element
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
void quickSort(vector <int> &arr, int low, int high)
{
    if (low < high)
    {  
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
int main()
{

    int t;
    cin >> t;
    while (t--)
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

        for (int i : arr) // i = 0; i < arr.size(); i++ and cout arr[i]
            cout << i << " ";
        cout << endl;
    }
    
    return 0;
}