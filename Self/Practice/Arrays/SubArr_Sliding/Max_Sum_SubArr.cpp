#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans,sum;
    for (int k = 1; k <= n; k++)
    {
        sum = 0;
        for (int i = 0; i < k; i++)
            sum += arr[i];

        ans = max(ans,sum);
        for (int i = k; i < n; i++)
        {
            sum += arr[i] - arr[i-k];
            ans = max(ans,sum);
        }
    }

    cout << ans << endl;
}