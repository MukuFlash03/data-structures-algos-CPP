#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    int temp[end-start+1];
    int i = start, j = mid+1, k=0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }   
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while(j <= end)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (i = start; i <= end; i++)
        arr[i] = temp[i-start];

}

void mergeSort(vector <int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end)/2;
        mergeSort(arr, start, mid);
        //cout << "MS L done for start = " << start << endl;
        mergeSort(arr, mid+1, end);
        //cout << "MS R for end = " << end << endl;
        merge(arr, start, mid, end);
        //cout << "Merge done for start = " << start << "\tend = " << end << endl;
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

    mergeSort(arr, 0, size-1);
    cout << "Sorted Data:\n";

    for (int i : arr) // i = 0; i < arr.size(); i++ and cout arr
        cout << i << " ";
    cout << endl;
    
    return 0;
}