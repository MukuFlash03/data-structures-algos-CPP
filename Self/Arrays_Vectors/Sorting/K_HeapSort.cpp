/*
https://www.commonlounge.com/discussion/bd7898f6be2344109683d2fe3cc70a8b
*/

#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 

void heapify(int arr[], int n, int i) 
{ 
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 
		heapify(arr, n, largest); 
	} 
} 

void heapSort(int arr[], int n) 
{ 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 

	for (int i=n-1; i>0; i--) 
	{ 
		swap(arr[0], arr[i]); 
		heapify(arr, i, 0); 
	} 
} 

void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

int main() 
{ 
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		vector <long long> temp;
		long long num;
		while (k--)
		{
			int n;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> num;
				temp.push_back(num);
			}
		}
		
		int arr[temp.size()];
		for (int i = 0 ; i < temp.size(); i++)
			arr[i] = temp[i];
		

		heapSort(arr, temp.size()); 

		printArray(arr, temp.size()); 
	}
	return 0;
}