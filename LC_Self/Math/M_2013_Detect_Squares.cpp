/*

Problem: https://leetcode.com/problems/detect-squares
Solution(s): 

https://stackoverflow.com/questions/48507427/c-when-to-use-the-new-keyword-when-creating-a-class-object
https://www.w3schools.com/cpp/cpp_classes.asp

YouTube
NC - https://www.youtube.com/watch?v=bahebearrDc
*/

/*

A. Optimal Solution (Recursive)

- Create a map of vector<int> and int to store the points
- Create a constructor to initialize the map
- Create an add function to add a point to the map
- Create a count function to count the number of squares
- Iterate through the map and check if the points are valid
    - If point is diagonal, which is checked by comparing if width and height are equal, and the point is not the same as the input point
        - If other two points are present with mathching x and y coordinates
            Then increment the answer.
- Return the answer


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<unordered_set>
#include<vector>
#include<map>

using namespace std;

class DetectSquares {
public:
    map<vector<int>, int> points;
    DetectSquares() {
    
    }
    
    void add(vector<int> point) {
        points[point]++;
        // cout << "Freq after adding: " << points[point] << "\n";
    }
    
    int count(vector<int> point) {
        int answer = 0;
        for (const auto& [p, count] : points) {
            if ((abs(p[0] - point[0]) == abs(p[1] - point[1])) && p != point) {
                if ((points.find({p[0], point[1]}) != points.end()) && 
                    (points.find({point[0], p[1]}) != points.end())
                ) {
                    answer += count * points[{p[0], point[1]}] * points[{point[0], p[1]}];
                    // cout << "Count to be added: " << count << "\n";
                    // cout << "Four Points are : " << 
                    //     "(" << p[0] << ", " << p[1] << ")" << ", " << 
                    //     "(" << p[0] << ", " << point[1] << ")" << ", " << 
                    //     "(" << point[0] << ", " << p[1] << ")" << ", " << 
                    //     "(" << point[0] << ", " << point[1] << ")" << "\n";
                }
            }
        }
        return answer;
    }
};


int main() {

    DetectSquares* detectSquares = new DetectSquares();
    detectSquares->add({3, 10});
    detectSquares->add({11, 2});
    detectSquares->add({3, 2});
    cout << detectSquares->count({11, 10}) << "\n"; // return 1. You can choose:
    cout << detectSquares->count({14, 8}) << "\n";  // return 0. 
    detectSquares->add({11, 2});
    cout << detectSquares->count({11, 10}) << "\n"; 
    delete detectSquares;

    return 0;
}