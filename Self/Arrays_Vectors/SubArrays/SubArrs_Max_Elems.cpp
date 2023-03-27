#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector <int> nums(n);
    vector <int> temp(k);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int j = 0; j <= n-k; j++)
    {
        temp.clear();
        for (int i = j; i < j+k; i++)
        {
            temp.push_back(nums[i]);
            // cout << nums[i] << " ";
        }
        // cout << endl;
    
        int maxEl = *max_element(temp.begin(), temp.end());
        cout << maxEl << " ";
        // cout << endl;
    }
    cout << endl;
}