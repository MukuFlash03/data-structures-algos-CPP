#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x;
    cin >> n >> k;
    vector <int> arr;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    for (int i = 0; i < k; i++) 
        arr.push_back(arr[i]);

    arr.erase(arr.begin(), arr.begin()+k);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}