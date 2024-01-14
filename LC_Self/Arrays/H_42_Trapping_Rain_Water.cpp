/*
Type: Two Pointers

Problem: https://leetcode.com/problems/trapping-rain-water
Solution(s): 
https://leetcode.com/problems/trapping-rain-water/solutions/4158470/3-lines-solution-with-explaination/
https://leetcode.com/problems/trapping-rain-water/solutions/3401992/100-detailed-explaination-with-pictures-in-c-java-python-two-pointers/


YouTube
NC - https://www.youtube.com/watch?v=ZI2z5pq0TqA
*/


/*
1. Initial Approach

Tried to solve it using two pointers.
I set l and r initially to 0.
THen I check if height[r] > height[l], if yes, then I set l = r.
Else, I calculate the local area and add it to the ans.
I increment r.
I keep doing this till r < height.size().
But this fails for all cases where we have a peak in the middle.
Since we don't have the next highest peak to bound the water, we can't calculate the local area.
This can be seen in the first test case itself.

2. LMax and RMax Approach with extra space

Two pointers is needed, but we need to start from both ends.
We need to keep track of the max height from left and right.
We need to keep track of the current height.
We need to keep track of the current area.
We need to keep track of the total area.

We can use two arrays one for maxLeft and another for maxRight.
Then can calculate area for each index using the following equation:
Equation = min(leftMax, rightMax) - currentHeight

If area goes -ve, we set it to 0.

3. LMax and RMax Approach without extra space

*** Crux of the explanation at 12:47 !!!

We can use two pointers one for left and another for right.
We can calculate the maxLeft and maxRight on the fly.
While we don't have the latest right or left max, we only need the minimum of the two at any given time.
We are incrementing the pointer which has the smaller value.
If both equal, increment either one. 
THus we are moving towards the max value while having the minimum of the two max values.

We can calculate area for each index using the following equation:
Equation = min(leftMax, rightMax) - currentHeight

If area goes -ve, we set it to 0.
If updating leftMax before computing current area, can skip the -ve check.

Edge case: Empty height vector, return 0.

 

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int trap(vector<int>& height) {
    if (height.size() == 0)
        return 0;

    int l = 0, r = height.size() - 1;
    int ans = 0, leftMax = height[l], rightMax = height[r];

    while (l < r) {
        if (leftMax < rightMax) {
            l++;
            leftMax = max(leftMax, height[l]);
            ans += leftMax - height[l];
        }
        else {
            r--;
            rightMax = max(rightMax, height[r]);
            ans += rightMax - height[r];
        }
    }
    return ans;
}



int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    // vector<int> nums = {4,2,0,3,2,5};

    int answer = trap(height);
    cout << answer << '\n';

}