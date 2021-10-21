#include <iostream>
#include <vector>
using namespace std;

int findMinIndex (vector <int> &arr, int start)
{
    int min_index = start++;
    for (int i = start; i < arr.size(); i++)
    {
        if(arr[i] < arr[min_index])
            min_index = i;
    }
    return min_index;
}

void selectionSort(vector <int> &arr)
{
    for (int i =0; i < arr.size(); i++)
    {
        int min_index = findMinIndex(arr, i);
        if (i != min_index)
            swap(arr[i], arr[min_index]);
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

    selectionSort(arr);
    cout << "Sorted Data:\n";

    for (int i : arr)
        cout << i << " ";
    
    return 0;
}