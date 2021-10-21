/*
https://www.commonlounge.com/discussion/f1ea531c22d84bfbb20db597b89b0aef
*/

#include <iostream>
#include <vector>
using namespace std;

long long int count = 0;

void merge(vector<int> &arr, int start, int mid, int end)
{
    int temp[end-start+1];
    int i = start, j = mid+1, k=0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            count += mid - i + 1;
            //cout << i << "\t" << j-1 << endl;
        }
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
        count = 0;
        vector <int> arr;
        int a, size;
        cin >> size;

        for (int i = 0; i < size; i++)
        {   
            cin >> a;
            arr.push_back(a);
        }

        mergeSort(arr, 0, size-1);

        cout << count << endl;
    }
    return 0;
}