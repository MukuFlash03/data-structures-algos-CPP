#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.begin() == nums.end())
        return 0;
    int temp = nums[0];
    int ind = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != temp)
        {
            temp = nums[i];
            swap(nums[i], nums[ind]);
            ind++;
        }
    }
    return ind;
}
int main()
{
    int n;
    cin >> n;
    vector<int> A;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int nl = removeDuplicates(A);
    if (nl == 0)
        cout << A[0];
    else
    {
        for (int i = 0; i < A.size(); i++)
            cout << A[i];
    }
    return 0;
}