/*


Problem: https://leetcode.com/problems/maximum-product-subarray/
Solution(s): 
https://leetcode.com/problems/maximum-product-subarray/solutions/1608862/java-3-solutions-detailed-explanation-using-image/
https://leetcode.com/problems/maximum-product-subarray/solutions/183483/java-c-python-it-can-be-more-simple/
https://leetcode.com/problems/maximum-product-subarray/solutions/1608800/c-discussion-in-detail-easy-to-understand/
https://leetcode.com/problems/maximum-product-subarray/solutions/1609493/c-simple-solution-w-explanation-optimization-from-brute-force-to-dp/


YouTube
NC - https://www.youtube.com/watch?v=lXVy6YWFcRM


A. Dynamic Programming

- In case of all +ve nums, product is always increasing
- In case of all -ve nums, product alternates between +ve and -ve

- We will need to keep track of both "max" and "min" products for each subarray
E.g. {-1,-2,-3,-4}
For {-1,-2} -> (max,min) = (2,-2)
For {-1,-2,-3} -> (max,min) = (6,-6)

max is the +ve magnitude, min is the -ve magnitude
Doesn't matter if next number is + or -, can keep computing both +ve and -ve magnitudes at each step.


Edge case: If 0 is encountered, it will basically reset, nullify product obtained till now.
To handle this, every time 0 is encountered, reset (max,min) to 1.
Now for next elements, they will be multiplied with 1 and entire product will not remain 0.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


int maxProduct(vector<int>& nums) {

    int maxProd = 1, minProd = 1;
    int result = INT_MIN;

    for (const auto &elem : nums)
        result = max(result, elem);

    for (const auto &elem : nums) {

        if (elem == 0) {
            maxProd = 1;
            minProd = 1;
            continue;
        }

        // Storing maxProd since it previous value overwritten before being used in computing minProd
        int tempMax = maxProd; 

        maxProd = max(max(maxProd * elem, minProd * elem), elem);
        minProd = min(min(tempMax * elem, minProd * elem), elem);

        result = max(result, maxProd);
    }
    return result;   
}


int main() {
    vector<int> nums = {2,3,-2,4};
    // vector<int> nums = {-2,0,-1};

    int maxProd = maxProduct(nums);
    cout << maxProd << endl;

    return 0;
}