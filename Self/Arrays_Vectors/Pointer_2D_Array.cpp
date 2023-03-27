// C++ program to find size of an array by using a 
// pointer hack. 
#include <bits/stdc++.h> 
#include <stdio.h>
#include <iostream>
using namespace std; 

int main() 
{ 
	int arr[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
	int m = sizeof(arr)/sizeof(arr[0]);
    int n = sizeof(arr[0])/sizeof(arr[0][0]);
    cout<< m <<" "<< n <<endl;
	
	int (*p)[3]= arr;
	cout << p << endl;
	cout << *p << endl;
	cout << p+1 << endl;
	cout << *(p+1) << endl;
	cout << *(*(p+1)) << endl;
	cout << *(*p+1) << endl;
	cout << *(*(p+2)+1) << endl;

	return 0; 
} 