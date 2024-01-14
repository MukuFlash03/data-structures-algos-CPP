/*
Type: Monotonic Decreasing Stack ; Next Greater Element
Problem: https://leetcode.com/problems/daily-temperatures/
Solution(s): 
https://leetcode.com/problems/daily-temperatures/discuss/1574806/C%2B%2B-EASY-standard-sol-oror-INTUITIVE-approach-with-DRY-RUN-oror-STACK-appraoch
https://leetcode.com/problems/daily-temperatures/discuss/1574808/C%2B%2BPython-3-Simple-Solutions-w-Explanation-Examples-and-Images-or-2-Monotonic-Stack-Approaches
https://leetcode.com/problems/daily-temperatures/discuss/2701164/C%2B%2B-5-Ways-to-solve-oror-Logic-%2B-Code

YouTube
NC - https://www.youtube.com/watch?v=cTBiBSnjO3c
Nice visual explanation - https://www.youtube.com/watch?v=WGm4Kj3lhRI
*/


/*

1. Brute Force
Right traversal -> TLE
Left traversal works slightly better but still gives TLE 
- We can break loop when first higher temp is reached and answer[i] != 0 anymore

2. Optimal solution
Start from end
- We know ahead of time all the warmer days
- Can create an algorithm with linear time complexity

We'll use a stack, why?
- LIFO principle
- At each iteration starting backwards, the last element placed on the stack represents the next day
- If this next day isn't a warmer day then we can keep popping the stack until we find a warmer day if it exists.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> answer(temperatures.size(), 0);
    int left = 0, right = 1;
    for (; left < temperatures.size(); left++) {
    //  for (; right > left; right--) {
        for (right = left + 1; right < temperatures.size() && !answer[left]; right++) {
            if (temperatures[right] > temperatures[left])
                answer[left] = right - left;
        }
    }
    return answer;
}
*/

// Iteration from the front
vector<int> dailyTemperaturesFront(std::vector<int>& temperatures) {
    
    stack<pair<int, int>> temp;
    vector<int> answer(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); i++) {
        while (!temp.empty() && temperatures[i] > temp.top().second) {
            answer[temp.top().first] = i - temp.top().first;
            temp.pop();
        }
        temp.push({i, temperatures[i]});
    }

    return answer;
}

// Iteration from the end
vector<int> dailyTemperaturesEnd(std::vector<int>& temperatures) {
    
    stack<pair<int, int>> temp;
    vector<int> answer(temperatures.size(), 0);

    for(int i = temperatures.size() - 1; i >= 0; i--) {
        int currTemp = temperatures[i];
            
        while (!temp.empty() && currTemp >= temp.top().second) {
            temp.pop();
        }

        // if (!temp.empty() && currTemp < temp.top().second)
        if (!temp.empty())
            answer[i] = temp.top().first - i;

        temp.push({i, currTemp});   
    }
    return answer;
}



int main() {
    // vector<int> nums = {73,74,75,71,69,72,76,73};
    // vector<int> nums = {30,40,50,60};
    // vector<int> nums = {30,60,90};
    vector<int> nums = {89,62,70,58,47,47,46,76,100,70};
    vector<int> answerFront = dailyTemperaturesFront(nums);
    vector<int> answerEnd = dailyTemperaturesEnd(nums);

    cout << "Front: \n";
    for(auto it = answerFront.begin(); it != answerFront.end(); it++)
        cout << *it << " ";
    cout << "\n\n";

     cout << "End: \n";
    for(auto it = answerEnd.begin(); it != answerEnd.end(); it++)
        cout << *it << " ";
    cout << '\n';

    /*
    vector<pair<int, int>> test = {make_pair(1,1), make_pair(2,2)};
    // vector<pair<int, int>>::iterator it;
    for (auto it = test.begin(); it != test.end(); it++)
            cout << it->first << ", " << it->second << '\t';
    cout << '\n';

    for (const pair<int,int> &elem : test)
        cout << elem.first << ", " << elem.second << '\t';
    cout << '\n';
    */

}