// CPP program to count 
// subarrays having sum 
// less than k. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find number 
// of subarrays having sum 
// less than k. 
int countSubarray(int arr[], 
				int n, int k) 
{ 
	int count = 0; 

	for (int i = 0; i < n; i++) { 
		int sum = 0; 
		for (int j = i; j < n; j++) { 

			// If sum is less than k 
			// then update sum and 
			// increment count 
			if (sum + arr[j] < k) { 
				sum = arr[j] + sum; 
				count++; 
			} 
			else { 
				break; 
			} 
		} 
        cout << endl;
	} 

	return count; 
} 

// Driver Code 
int main() 
{ 
	int array[] = { 1, 11, 2, 3, 15 }; 
	int k = 10; 
	int size = sizeof(array) / sizeof(array[0]); 
	int count = countSubarray(array, size, k); 
	cout << count << "\n"; 
}