#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = INT_MAX, sum;

    for (int k = 1; k < n; k++)
    {
        for (int i = 0; i < k; i++)
            sum += arr[i];
        
        if (sum > s)
            ans = min(ans,k);

        for (int i = k; i < n; i++)
        {
            sum += arr[i] - arr[i-k];
            if (sum > s)
                ans = min(ans,k);
        }
    }
    cout << ans << endl;
}