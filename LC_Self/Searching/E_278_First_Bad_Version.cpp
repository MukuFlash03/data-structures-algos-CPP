/*
Type: Searching Array
Problem: https://leetcode.com/problems/first-bad-version/description/
Solution(s): 
- https://leetcode.com/problems/first-bad-version/solutions/3361234/0ms-best-c-solution/
- https://leetcode.com/problems/first-bad-version/solutions/3347493/c-easy-using-binary-search-o-logn/

*/


/*

A. Optimal Solution

1. Compare low LTE high and keep searching while this is true.
2. Compare target with middle value, 
3.  If greater, set low to one more than mid.
4.  If lesser, set high to one less than mid.
5.  Else, if equal, return mid.
6. Outside loop, return -1; to indicate the target was not found.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<bool> marks;

int search(vector<int>& nums, int target) {

    if (nums.size() == 1 && nums[0] == target)
        return 0;
    if (nums.size() == 1 && nums[0] != target)
        return -1;

    int low = 0, high = nums.size()-1, mid;

    while (low <= high) {
        mid = (low + high)/2;

        if (target > nums[mid])
            low = mid + 1;
        else if (target < nums[mid])
            high = mid - 1;
        else if (target == nums[mid])
            return mid;
    }
    return -1;
}


void markBadVersion(int n, int bad) {
    bool flag = false;
    marks.push_back(flag);

    for (int i = 1; i <= n; i++) {
        if (i == bad)
            flag = true;
        marks.push_back(flag);
    }
}

bool isBadVersion(int version) {
    return marks[version];
}

int firstBadVersion(int n) {
        int low = 1, high = n, ans, mid;

        if (n == 1 && marks[n] == true)
            return 1;

        while(low <= high) {
            mid = low + (high - low)/2;
            if(isBadVersion(mid) == false)
                low = mid + 1;
            else {
                ans = mid;
                if(mid == 1 || isBadVersion(mid-1) == false) 
                    return mid;
                high = mid - 1;
            }
        }
        return ans;
    }


int main() {

    int n = 5, bad = 4;
    
    markBadVersion(n, bad);
    cout << firstBadVersion(n) << "\n";

}