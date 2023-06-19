/*
Type: Two Pointers

Problem: https://leetcode.com/problems/container-with-most-water/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=UuiTKBwPgAo
*/


/*

1. Brute Force
L = 0, R = L+1
Width = R-L;    Height = min(L,R)
Compute area and update max area

2. Optimal solution
- L = 0, R = n-1 -> since we want to maximize area, choosing max width (separation between L,R)
- Updating pointers: Shift the min ptr value
                        since we want to maximize area, we will not move max ptr
                    If both ptr values equal, can shift either one (condense if-else)


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int maxArea(vector<int>& height) {
    
    int l = 0, r = height.size() - 1;
    int answer = 0, area = 1;

    while (l < r) {
        area = (r-l) * min(height[l], height[r]);
        answer = max(answer, area);

        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return answer;
}



int main() {
    std::vector<int> nums = {1,8,6,2,5,4,8,3,7};
    // std::vector<int> nums = {1,1};

    int answer = maxArea(nums);
    cout << answer << '\n';

}