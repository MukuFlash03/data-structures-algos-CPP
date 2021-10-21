// C++ program to find size of an array by using a 
// pointer hack. 
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6}; 
	int size = *(&arr + 1) - arr; 
	
	cout << "\n" << "Number of elements in arr[] is " << size << "\n"; 
	cout << "\n" << arr << "\n";
	cout << "\n" << &arr << "\n";
	cout << "\n" << &arr + 1 << "\n";
	cout << "\n" << *(&arr + 1) << "\n";
	cout << "\n" << *(&arr + 1) - arr << "\n";
	
	return 0; 
} 