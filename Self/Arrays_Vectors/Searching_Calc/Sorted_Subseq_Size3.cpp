/*
Problem:
https://www.geeksforgeeks.org/find-a-sorted-subsequence-of-size-3-in-linear-time/
https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1
*/

#include <bits/stdc++.h> 
using namespace std; 

void find3Numbers(int arr[], int n) 
{
	int max = n - 1, min = 0, i;

	// Create an array that will store 
    // index of a smaller element on left side. 
	// If there is no smaller element on left side,
    // then smaller[i] will be -1. 
	int* smaller = new int[n]; 
    smaller[0] = -1;    // first entry will always be -1 
	
	for (i = 1; i < n; i++)
    {
		if (arr[i] <= arr[min])
        {
			min = i; 
			smaller[i] = -1; 
		} 
		else
			smaller[i] = min; 
	} 

	// Create another array that will store index of a greater element 
	// on right side. 
    // If there is no greater element on right side, then 
	// greater[i] will be -1. 
	int* greater = new int[n]; 
    greater[n - 1] = -1;    // last entry will always be -1 

	for (i = n - 2; i >= 0; i--)
    {
		if (arr[i] >= arr[max])
        {
			max = i; 
			greater[i] = -1; 
		} 
		else
			greater[i] = max; 
	} 

	// Now find a number which has both 
	// a greater number on right side and 
	// smaller number on left side 
	for (i = 0; i < n; i++) 
    {
		if (smaller[i] != -1 && greater[i] != -1)
        {
			cout << arr[smaller[i]] << " " << arr[i] << " " << arr[greater[i]]; 
			return; 
		} 
	}

	// If we reach here, then there are no such 3 numbers 
	cout << "No such triplet found" << endl; 

	// Free the dynamically allocated memory 
	// to avoid memory leak 
	delete[] smaller; 
	delete[] greater; 

	return; 
} 

int main() 
{ 
	int arr[] = { 12, 11, 10, 5, 6, 2, 30 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	find3Numbers(arr, n); 
	return 0;
} 