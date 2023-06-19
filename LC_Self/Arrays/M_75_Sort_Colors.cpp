/*

Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/sort-colors/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=4xbWSRZHqac
https://www.youtube.com/watch?v=HmRWI_ypnM4
*/


/*

A. Bucket Sort (Trivial solution)

Two-pass: Once to categorize, next to build output.

1. Categorize into three buckets - 0, 1, 2
2. For each bucket, count the no. of items from input
3. Go to input array and replace each of the first k elements for each of the k items under each bucket.

B. Quick Sort Partition (One-pass using Two-pointers)

1. Left pointer starts at left-end and always points to 1's.
   Right pointer starts at right-end and can point to any value.
   i pointer iterates through array.

While i <= R
2. If 0 is encountered, elements at L and i are swapped.
3. If 2 is encountered, elements at R and i are swapped.
    i is decremented by 1
4. i is incremented by 1

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


void swap(vector<int>& nums, int x, int y) {
    int temp = nums[x];
    nums[x] = nums[y];
    nums[y] = temp;
}

void sortColors(vector<int>& nums) {

    int i = 0, l = 0, r = nums.size() - 1;

    while (i <= r) {
        if (nums[i] == 0) {
            swap(nums,l,i);
            l++;
        }
        else if (nums[i] == 2) {
            swap(nums,r,i);
            r--;
            i--;
        }
        i++;
    }
}


int main() {
    vector<int> nums = {2,0,1,0,2,1};
    
    sortColors(nums);

    for ( const int &elem : nums )
        cout << elem << '\t';
    cout << '\n';

    return 0;
}