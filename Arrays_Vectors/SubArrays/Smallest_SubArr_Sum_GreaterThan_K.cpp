/*
https://www.geeksforgeeks.org/smallest-subarray-from-a-given-array-with-sum-greater-than-or-equal-to-k/
https://www.geeksforgeeks.org/smallest-subarray-with-sum-k-from-an-array/?ref=leftbar-rightbar
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
    
    int sum = 0, temp = INT_MAX, len = 0;
    for (int j = 1; j <= n; j++)
    {
        sum = 0, len = 0;
        for (int i = 0; i < j; i++)
        {
            sum += nums[i];
            //len++;
        }
        
        if (sum >= k)
            temp = min(j,temp);
        //temp = min(temp,len);

        for (int i = j; i < n; i++)
        {
            sum += nums[i] - nums[i-j];
            if (sum >= k)
            {
                // cout << sum << endl;
                //len++;
                temp = min(j,temp);
            }
        }
    }
    cout << temp << endl;
}