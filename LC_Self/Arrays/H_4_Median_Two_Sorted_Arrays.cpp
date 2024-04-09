/*

Type: 

Problem: https://leetcode.com/problems/median-of-two-sorted-arrays
Solution(s): 
- https://www.codespeedy.com/merge-two-sorted-arrays-in-c/

YouTube
NC - https://youtu.be/q6IEA26hvXc?si=b4jtVj_zHnUKWolc&t=484
   - https://youtu.be/q6IEA26hvXc?si=9KQQQyi56sbBLW3u&t=731

*/

/*

A. Basic Approach

- Merge the two lists into one.
- Can use either LinkedList or Array to merge the lists.
- Find the median of the merged list.

B. Binary Search (Neetcode)

- Find the partition of the two lists such that the left half of the merged list is smaller than the right half.
- To compute partition, use binary search on the smaller list.
    - If the merged list is even, the left partition will have half the elements.
    - If the merged list is odd, the left partition will have half the elements + 1.
- The left partition of smaller list will have mid elements, and
    - the left partition of the larger list will have (m+n+1)/2 - mid elements, if odd.
    - the left partition of the larger list will have (m+n)/2 - mid elements, if even.
    - Initially, mid = (l + r) / 2.
- To know whether you have the correct left partition, check if:
    - The last element of the left partition of list1 is smaller than the first element of the right partition of list2.
    - The last element of the left partition of list2 is smaller than the first element of the right partition of list1.
- If partition is not correct, adjust the partition:
    - If the last element of the left partition of list1 is greater than the first element of the right partition of list2, move r to i - 1.
    - If the last element of the left partition of list2 is greater than the first element of the right partition of list1, move l to i + 1.
- For odd number of elements, return the minimum of the first element of the right partition of list1 and the first element of the right partition of list2.
- For even number of elements, return the average of:
    - the maximum of the last element of the left partition of list1 and the last element of the left partition of list2, and 
    - the minimum of the first element of the right partition of list1 and the first element of the right partition of list2.

C. Binary Search (Editorial)

Two conditions to check:
1. k > aInd + bInd OR 2. k <= aInd + bInd
I. aMid <= bMid OR II. aMid > bMid

        |        Cond I            ||          Cond II
        |    ---------------       ||      -------------
Cond 1  |    Al || Ar + Br         ||       Bl || Br + Ar
Cond 2  |    Al +  Bl || Br        ||       Al + Bl || Ar



Algorithm
Let's define a function that helps us find the kthk^{th}k th smallest element from two inclusive ranges [a_start, a_end] and [b_start, b_end] from arrays A and B.

Let m = size of A and n = size of B. 
- For odd, k = (m + n + 1) / 2, and 
- For even, k = (m + n) / 2 - 1 and k = (m + n) / 2.

1. If the range (for example, a range of A) is empty, in other words a_start > a_end, it means all elements in A are passed, we just return the (k - a_start)-th element from the other array B. Vice versa if b_start > b_end.
2. Otherwise, get the middle indexes of the two ranges: a_index = (a_start + a_end) / 2, b_index = (b_start + b_end) / 2.
3. Get the middle values of the two ranges: a_value = A[a_index], b_value = B[b_index].
4. Cut one array in half, according to:
    - If a_index + b_index < k, cut one smaller half.
        - If a_value < b_value, cut the smaller half of A.
        - Otherwise, cut the smaller half of B.
    - Otherwise, cut one larger half.
        - If b_value < a_value, cut the larger half of B.
        - Otherwise, cut the larger half of A.
5. Repeat step 1 using the new starting and ending indexes of A and B.

6. Then we move on to find the median elements, and get the length of both arrays na = len(A) and nb = len(B).
    - If the total number of elements in A and B is odd, we just use the above function to find the middle element, that is k = (na + nb) / 2.
    - Otherwise, we use the function to find two middle elements: k = (na + nb) / 2 - 1 and k = (na + nb) / 2, and return their average.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
// #include "../Linked_List/CustomLL.h"

using namespace std;

/*
// M1: Merge arrays and find median

CustomLL::ListNode* mergeTwoLists(CustomLL::ListNode* list1, CustomLL::ListNode* list2) {
    CustomLL::ListNode* dummy = new CustomLL::ListNode();
    CustomLL::ListNode* result = dummy;

    while (notEmptyList(list1) && notEmptyList(list2)) {
        if (list1->val < list2->val) {
            result->next = list1;
            list1 = list1->next;
        }
        else {
            result->next = list2;
            list2 = list2->next;
        }
        result = result->next;
    }

    if (notEmptyList(list1))
        result->next = list1;
    else if (notEmptyList(list2))
        result->next = list2;

    return dummy->next;
}

double findMedian(vector<int> nums) {
    int len = nums.size();
    if (len % 2 != 0)
        return nums[len/2];
    return (double)(nums[len/2 - 1] + nums[len/2]) / 2;
}

vector<int> mergeTwoLists(vector<int> nums1, vector<int> nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int i = 0, j = 0;
    vector<int> mergedArr;

    while(i < m && j < n) {
        if(nums1[i] < nums2[j])
            mergedArr.push_back(nums1[i++]);
        else
            mergedArr.push_back(nums2[j++]);
    }

    while(i < m)
        mergedArr.push_back(nums1[i++]);
    while(j < n)
        mergedArr.push_back(nums2[j++]);

    return mergedArr;
} 

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    CustomLL cll;
    // CustomLL::ListNode* head1 = cll.createLL(nums1);
    // CustomLL::ListNode* head2 = cll.createLL(nums2);
    // CustomLL::ListNode* mergedHead = mergeTwoLists(head1,head2);        
    // vector<int> nums = cll.getListFromLL(mergedHead);

    vector<int> nums = mergeTwoLists(nums1, nums2);
    
    return findMedian(nums);
}
*/

// M2: Binary Search

int solve(vector<int>& A, vector<int>& B, int k, int aStart, int aEnd, int bStart, int bEnd) {
    // If the segment of on array is empty, it means we have passed all
    // its element, just return the corresponding element in the other array.
    if (aEnd < aStart) {
        return B[k - aStart];
    }
    if (bEnd < bStart) {
        return A[k - bStart];
    }

    // Get the middle indexes and middle values of A and B.
    int aIndex = (aStart + aEnd) / 2, bIndex = (bStart + bEnd) / 2;
    int aValue = A[aIndex], bValue = B[bIndex];
    
    // If k is in the right half of A + B, remove the smaller left half.
    if (aIndex + bIndex < k) { 
        if (aValue > bValue) {
            return solve(A, B, k, aStart, aEnd, bIndex + 1, bEnd);
        } else {
            return solve(A, B, k, aIndex + 1, aEnd, bStart, bEnd);
        }
    } 
    // Otherwise, remove the larger right half.
    else { 
        if (aValue > bValue) {
            return solve(A, B, k, aStart, aIndex - 1, bStart, bEnd);
        } else {
            return solve(A, B, k, aStart, aEnd, bStart, bIndex - 1);       
        }
    }
    return -1;
}

double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int na = int(A.size()), nb = int(B.size());
    int n = na + nb;
    if (n % 2) {
        return solve(A, B, n / 2, 0, na - 1, 0, nb - 1);
    } else {
        return 1.0 * (solve(A, B, n/2 - 1, 0, na - 1, 0, nb - 1) + solve(A, B, n/2, 0, na - 1, 0, nb - 1)) / 2;
    } 
}


int main() {

    vector<int> list1 = {1,3}, list2 = {2};
    // vector<int> list1 = {1,2}, list2 = {3,4};

    cout << findMedianSortedArrays(list1, list2) << "\n";

    return 0;
}