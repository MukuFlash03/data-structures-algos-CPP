#include <algorithm>
#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    unsigned long n;
	    cin>>n;
	    unsigned long long *a = new unsigned long long[n];
	    for(unsigned long i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
	    unsigned long *minAIndex = new unsigned long[n];
	    minAIndex[0] = 0;
	    for(unsigned long i=1; i<n; i++)
	    {
	        minAIndex[i] = a[i] < a[minAIndex[i-1]] ? i : minAIndex[i-1];
            cout << minAIndex[i] << " ";
	    }
        cout << endl;
	    unsigned long *maxAIndex = new unsigned long[n];
	    maxAIndex[n-1] = n-1;
	    for(unsigned long i=n-1; i>0; i--)
	    {
	        maxAIndex[i-1] = a[i-1] > a[maxAIndex[i]] ? i-1 : maxAIndex[i];
            cout << maxAIndex[i] << " ";
	    }
        cout << endl;
	    unsigned long indexDifferenceMax = 0;
	    for(unsigned long i=0, j=0; i<n && j<n;)
	    {
	        if(a[minAIndex[i]] <= a[maxAIndex[j]])
	        {
	            indexDifferenceMax = max(indexDifferenceMax, j-i);
	            j++;
	        }
	        else
	        {
	            i++;
	        }
	    }
	    cout <<indexDifferenceMax<< endl;
	    delete []a;
	    delete []minAIndex;
	    delete []maxAIndex;
	}
	return 0;
}