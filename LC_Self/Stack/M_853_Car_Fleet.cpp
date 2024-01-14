/*
Problem: https://leetcode.com/problems/car-fleet
Solution(s): 
- https://leetcode.com/problems/car-fleet/solutions/4142528/easy-c-solution-detailed-explanation-o-nlogn/
- https://leetcode.com/problems/car-fleet/solutions/4142249/c-code-with-in-depth-explanation-easy-to-understand-solution-o-n/
- https://leetcode.com/problems/car-fleet/solutions/4010489/c-solution-using-pairs-and-sorting-easy-to-understand/

YouTube
NC - https://www.youtube.com/watch?v=Pr6T-3yB9RM
*/


/*


A. Optimal Solution

- Iterate in reverse order since the cars moving from behind will have its speed reduced if the car ahead is slower.
- Calculate the time taken by the car to reach the target.
- If the time taken by the car ahead is greater than the car behind, then the car behind will not be able to catch up with the car ahead.

B. Stack Solution

- Same concept but use a stack to store time and compare two cars at a time.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<map>


using namespace std;

// A. Non-Stack Solution
int carFleetA(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, double>> posTime;
    int fleetCtr = 1;

    for (int i = 0; i < position.size(); i++)
        posTime.push_back({position[i], (double)((target - position[i]) / speed[i])});

    sort(posTime.begin(), posTime.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.first > b.first;
    });
    
    double slowTime = posTime[0].second;

    for (int i = 1; i < posTime.size(); i++) {
        if (posTime[i].second > slowTime) {
            fleetCtr++;
            slowTime = posTime[i].second;
        }
    }

    return fleetCtr;
}

// B. Stack Solution
int carFleetB(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, double>> posTime;

    for (int i = 0; i < position.size(); i++)
        posTime.push_back({position[i], static_cast<double>(target - position[i]) / speed[i]});

    sort(posTime.begin(), posTime.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.first > b.first;
    });
    
    stack<double> carTime;

    for (const auto& elem : posTime) {
        if(!carTime.empty() && elem.second > carTime.top())
                carTime.push(elem.second);
        else if (carTime.empty())
                carTime.push(elem.second);
    }

    return carTime.size();
}

int main() {

    // int target = 12;
    // vector<int> position = {10,8,0,5,3}, speed = {2,4,1,1,3};

    // int target = 10;
    // vector<int> position = {3}, speed = {3};

    int target = 100;
    vector<int> position = {0,2,4}, speed = {4,2,1};

    cout << carFleetA(target, position, speed) << "\n";
    cout << carFleetB(target, position, speed) << "\n";

    return 0;
}


