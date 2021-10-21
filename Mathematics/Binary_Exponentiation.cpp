#include <bits/stdc++.h>
using namespace std;

#define PRIME 1000000007
// Or any prime 
// Returns (x^n) % PRIME

long long int binary_exp(long long int x, long long int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return x % PRIME;
    else
    {
        long long int temp = binary_exp(x, n / 2);
        temp = (temp * temp) % PRIME;
         
        if (n % 2 == 0)
            return temp;
        else
            return ((x % PRIME) * temp) % PRIME;
    }
}

/* Iterative Function to calculate (x^y) in O(log y) */
int power(int x, unsigned int y) 
{ 
	int res = 1;	 // Initialize result 

	while (y > 0) 
	{ 
		// If y is odd, multiply x with result 
		if (y & 1) 
        {
			res = res*x;
            cout << res << " ";
        }
		// y must be even now 
		y = y>>1; // y = y/2 
		x = x*x; // Change x to x^2 
        cout << y << " " << x << endl;
	} 
	return res; 
}


int main()
{
    long long int x,n;
    cin >> x >> n;
    cout << binary_exp(x,n) << endl;
    cout << power(x,n) << endl;
    return 0;
}