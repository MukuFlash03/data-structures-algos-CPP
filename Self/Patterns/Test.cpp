#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = n; i >= 1; i--)
		{
			for (int j = n; j >= 1; j--)
			{
				for (int k = i; k >= 1; k--)
					cout << j << " ";
			}
			cout << "$";
		}
	}
}