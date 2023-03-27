#include <bits/stdc++.h> 
using namespace std; 

int minCount(int A, Int B, int C, int D, int X) 
{ 
	// we will only store min counts 
	// of sum upto 100 
	int memo[100]; 

	// initialize with INT_MAX 
	for (int i = 0; i < 100; i++) { 
		memo[i] = INT_MAX; 
	} 

	// memo[0] = 0 as 0 is 
	// made from 0 elements 
	memo[0] = 0; 

	// fill memo array with min counts 
	// of elements that will constitute 
	// sum upto 100 

	for (int i = 1; i < 100; i++) { 
		memo[i] = min(memo[i - 1] + 1, memo[i]); 
	} 

	for (int i = 10; i < 100; i++) { 
		memo[i] = min(memo[i - 10] + 1, memo[i]); 
	} 

	for (int i = 25; i < 100; i++) { 
		memo[i] = min(memo[i - 25] + 1, memo[i]); 
	} 

	// min_count will store min 
	// count of elements chosen 
	long min_count = 0; 

	// starting from end iterate over 
	// each 2 digits and add min count 
	// of elements to min_count 
	while (X > 0) { 
		min_count += memo[X % 100]; 
		X /= 100; 
	} 

	return min_count; 
} 

// Driver code 
int main() 
{ 

	int a,b,c,d,x;
    cin >> a >> b >> c >> d >> x;

	cout << minCount(a,b,c,d,x) << endl; 

	return 0; 
}