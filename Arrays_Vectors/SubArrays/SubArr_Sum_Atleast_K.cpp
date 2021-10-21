#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector <int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int count = 0, sum = 0, temp = 0;
    for (int j = 1; j <= n; j++)
    {
        sum = 0, temp = 0;
        for (int i = 0; i < j; i++)
            sum += nums[i];

        if (sum >= k)
        {
            count++;
            // cout << sum << " " << count << endl;
        }

        // temp = sum;
        for (int i = j; i < n; i++)
        {
            sum += nums[i] - nums[i-j];
            // sum = max(sum,temp);
            // cout << sum << endl;
            if (sum >= k)
            {
                count++;
                //cout << sum << " " << count << endl;
            }
        }
    }
    /*sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    if (sum >= k)   count++;*/
    cout << count << endl;
}