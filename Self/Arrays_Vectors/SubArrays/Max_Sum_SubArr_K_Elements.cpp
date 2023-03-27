/*
https://www.geeksforgeeks.org/largest-sum-subarray-least-k-numbers/
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector <int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int sum = 0, temp = 0;
    for (int j = k; j <= n; j++)
    {
        sum = 0, temp = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i];

        temp = sum;
        for (int i = k; i < n; i++)
        {
            temp += nums[i] - nums[i-k];
            sum = max(sum,temp);
        }
    }
    cout << sum << endl;
}