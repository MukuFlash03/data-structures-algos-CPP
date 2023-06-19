/*
Type: Index as Hash Key
Problem: https://leetcode.com/problems/first-missing-positive/submissions/
Solution: https://leetcode.com/problems/first-missing-positive/discuss/2316294/C%2B%2B-oror-Easy-To-Understand
*/

/* Steps */
/*
Runtime, Memory: Soln 3 < Soln 2 < Soln 1

Soln 2: No extra DS used -> miss used.
1. Initialize miss = 1
2. Iterate through input nums.
3.  If *it < 1 => continue
4.  Else,
5.    If *it == miss => miss++ (move to next minimmum positive number)
6.    Else if *it > miss => return miss (answer = miss -> already incremented above)
7. Return miss (if no condition matches, at this point miss = nums.size() + 1)
------------------

Soln 1, 3:
1. Initialize tracking vector or map with 0 (len = nums.size() + 1)
2. Iterate through input array nums (all elements -> iterator)
3.   If element < 1 or element > nums.size() => continue
4.   Else, assign -1 to element's index in tracking vector/map.

Soln 3: For Vector implementation:
5. Iterate through tracking vector -> fo(1,nums.size())
6.  If ith element == 0 in tracking vector => Return i
// 7. Return nums.size() + 1
7. Return i

Soln 1: For Map implementation:
5. Iterate through tracking map -> fo(1,nums.size())
6.  If ith element not present in tracking map => break
7. If ith element == -1 => i++
8. Return i
------------------

Map = Vector
A. Step 7 = Step 7 (Commented step 7)
B. Step 8 = Step 6

This serves as a check for minimum positive number greater than last element in input nums.
This occurs when input nums are sorted AND all numbers are present in order from 1 to nums.size()
i becomes equal to nums.size() via iteration updates.
Hence answer = i++ or nums.size() + 1


In Vector implementation: Earlier Step 7 case is already covered in iteration since vector length = nums.size() + 1
In Map implementation: Step 7 is needed since map size = nums.size(); 
                       in case "sorted all present" scenario occurs, then i++ will give correct answer as nums.size() + 1
*/


#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    
    /* Soln 1 */
    /*     
    map<int, int> freqMap;
    for(auto it: nums) {
        if (it < 1 || it > nums.size())
            continue;
        freqMap[it] = -1;
    }
        
    int i = 1;
    for(; i < nums.size(); i++) {
        if (freqMap.find(i) == freqMap.end())
            break;
    }
    
    if (freqMap[i] == -1)
        i++;
    return i;
    */

    /* Soln 2 */
    /*
    int miss = 1;
    sort(nums.begin(),nums.end());
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        if (*it < 1) continue;
        else {
                if (*it == miss)
                    miss++;
                else if (*it > miss)
                    return miss;
        } 
    }
    return miss;
    */
    
    /* Soln 3 */
    // /*
    int len = nums.size();
    vector<int> arr(len+1,0);

    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
       if (*it < 1 || *it > nums.size())  
        continue;
       arr[*it] = -1;
    }

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == 0)
            return i;
    }

    return len + 1;
    // */
}

int main() {
    // vector<int> nums = {2, -5, 4, 3, 0, 7, 8, -10};
    vector<int> nums = {1,2,3,4,5};
    cout << firstMissingPositive(nums) << endl;
}