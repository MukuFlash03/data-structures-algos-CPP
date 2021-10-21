#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1,n2,x,i=0,j=0;
    cin >> n1 >> n2;
    vector <int> nums1;
    vector <int> nums2;
    vector <int> nums;

    for (int i = 0; i < n1; i++)
    {
        cin >> x;
        nums1.push_back(x);
    }

    for (int i = 0; i < n2; i++)
    {
        cin >> x;
        nums2.push_back(x);
    }

    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
            i++;
        else if (nums1[i] > nums2[j])
            j++;
        else
        {
            nums.push_back(nums2[j++]);
            i++;
        }
    }

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}