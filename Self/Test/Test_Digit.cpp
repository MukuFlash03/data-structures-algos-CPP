#include <bits/stdc++.h>
using namespace std;


int maxOccur(int *arr, int n, int k)
{
    int count = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        count = 0;
        while (num > 0)
        {
            count = (num % 10 == k) ? count+1 : count;
            num /= 10;
        }
        // cout << count << " for " << arr[i] << endl;
        ans = max(ans, count);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxOccur(arr,n,k) << endl;
    return 0;
}