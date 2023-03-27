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
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while(j <= end)
        temp[k++] = arr[j++];

    for (i = start; i <= end; i++)
        arr[i] = temp[i-start];

}

void mergeSort(vector <int> &arr, int start, int end)
{
    if (start == end) return;
    int mid = (start + end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
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

        mergeSort(arr, 0, size-1);

        for (int i : arr) // i = 0; i < arr.size(); i++ and cout arr[i]
            cout << i << " ";
        cout << endl;
    }
    
    return 0;
}