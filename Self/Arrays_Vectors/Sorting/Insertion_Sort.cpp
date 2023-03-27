#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector <int> &arr)
{
    int i,hole,key;

    for (i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        hole = i;

        while (hole > 0 && arr[hole-1] > key)
        {
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = key;
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

    insertionSort(arr);
    cout << "Sorted Data:\n";

    for (int i : arr) // i = 0; i < arr.size(); i++ and cout arr
        cout << i << " ";
    
    return 0;
}