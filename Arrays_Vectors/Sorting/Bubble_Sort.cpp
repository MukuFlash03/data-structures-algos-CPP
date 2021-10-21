#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector <int> &arr)
{
    int n = arr.size();
    for (int i =0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
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

    bubbleSort(arr);
    cout << "Sorted Data:\n";

    for (int i : arr)
        cout << i << " ";
    
    return 0;
}