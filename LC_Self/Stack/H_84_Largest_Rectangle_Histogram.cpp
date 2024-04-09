/*
Type: Monotonic Decreasing Stack ; Next/Previous Greater/Smaller Element
Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/
Solution(s): 
- https://medium.com/algorithms-digest/largest-rectangle-in-histogram-234004ecd15a
- https://leetcode.com/problems/largest-rectangle-in-hist ogram/solutions/1658644/increasing-monotonic-stacks-to-calculate-previous-smaller-and-next-smaller-element/

YouTube
NC - https://www.youtube.com/watch?v=zx5Sw9130L0
*/


/*

A. Brute force - O(n^2)

1. For each bar, find the count of bars on the left and right that are greater than or equal to the current bar.
2. Calculate the area with the current bar as the smallest bar.
3. Return the maximum area.

B. Optimal solution - O(n) - Previous and Next Smaller Element

1. Use a stack to implement the monotonic decreasing stack.
2. Find the indices of the previous smaller element and next smaller element for each bar in the array.
3. Calculate the area with the current bar as the smallest bar.
4. Return the maximum area.

C. Optimal solution - O(n) - No Previous and Next Smaller Element - Neetcode

1. Use a stack to keep track of indices and heights of the bars in the histogram. 
2. For each bar, they check if the current bar's height is less than the height of the bar at the top of the stack. 
3. If so, calculate the area formed by the popped bar and update the maximum area if necessary. 
4. Then, continue this process until you encounter a bar with a height greater than or equal to the current bar's height.
5. Finally, they handle the remaining bars in the stack to calculate the areas formed by them and update the maximum area if necessary.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> nums) {
    vector<int> answer(nums.size(), nums.size());
    stack<pair<int, int>> temp;

    for (int i = 0; i < nums.size(); i++) {
        while (!temp.empty() && nums[i] < temp.top().second) {
            answer[temp.top().first] = i;
            temp.pop();
        }
        temp.push({i, nums[i]});
    }
    return answer;
}

vector<int> previousSmallerElement(vector<int> nums) {
    vector<int> answer(nums.size(), -1);
    stack<pair<int, int>> temp;

    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!temp.empty() && nums[i] < temp.top().second) {
            answer[temp.top().first] = i;
            temp.pop();
        }
        temp.push({i, nums[i]});
    }
    return answer;
}

void printElements(vector<int> nums) {
    for (const auto& elem : nums) {
        cout << elem << "\t";
    }
    cout << "\n";
}

int largestRectangleArea(vector<int>& heights) {
    vector<int> nextSmallerHeights = nextSmallerElement(heights);
    vector<int> previousSmalleHeights = previousSmallerElement(heights);
    vector<int> maxHeights(heights.size(), 0);
    int answer = 0;

    for (int i = 0; i < heights.size(); i++) {
        int width = (nextSmallerHeights[i] - previousSmalleHeights[i]) - 1;
        maxHeights[i] = heights[i] * width;
        answer = max(answer, maxHeights[i]);
    }

    // printElements(heights);
    // printElements(previousSmalleHeights);
    // printElements(nextSmallerHeights);
    // printElements(maxHeights);

    return answer;
}

int largestRectangleAreaNC(vector<int>& heights) {
    stack<pair<int, int>> temp;
    int answer = 0;
    int start, width, maxHeight;

    for (int i = 0; i < heights.size(); i++) {
        start = i;
        while (!temp.empty() && heights[i] < temp.top().second) {
            pair<int, int> currIndHeight = temp.top();
            width = i - currIndHeight.first;
            maxHeight = currIndHeight.second * width;
            answer = max(answer, maxHeight);
            start = currIndHeight.first;
            temp.pop();
        }
        temp.push({start, heights[i]});
    }

    while (!temp.empty()) {
        pair<int, int> currIndHeight = temp.top();
        width = heights.size() - currIndHeight.first;
        maxHeight = currIndHeight.second * width;
        answer = max(answer, maxHeight);
        temp.pop();
    }

    return answer;
}

int main() {

    vector<int> heights = {2,1,5,6,2,3};
    // vector<int> heights = {2,4};
    int answer = largestRectangleArea(heights);
    int answerNC = largestRectangleAreaNC(heights);
    cout << answer << "\t" << answerNC << "\n";

    return 0;
}