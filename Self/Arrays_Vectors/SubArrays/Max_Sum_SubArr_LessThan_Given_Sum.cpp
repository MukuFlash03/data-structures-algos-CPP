/*
https://www.geeksforgeeks.org/maximum-sum-subarray-sum-less-equal-given-sum/
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
    for (int j = 1; j <= n; j++)
    {
        sum = 0;
        for (int i = 0; i < j; i++)
            sum += nums[i];
        
        if (sum <= k)
            temp = sum;
        else
            sum = temp;

        for (int i = j; i < n; i++)
        {
            sum += nums[i] - nums[i-j];
            if (sum <= k)
            {
                // cout << sum << endl;
                sum = max(sum,temp);
                temp = sum;
            }
            else
                sum = temp;
        }
    }
    cout << sum << endl;
}