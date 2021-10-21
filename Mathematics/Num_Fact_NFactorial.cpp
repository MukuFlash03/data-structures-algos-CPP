// C++ program to count number of factors of n 
#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll; 

// Sieve of Eratosthenes to mark all prime number 
// in array prime as 1 
void sieve(int n, bool prime[]) 
{ 
	// Initialize all numbers as prime 
	for (int i=1; i<=n; i++) 
		prime[i] = 1; 

	// Mark composites 
	prime[1] = 0; 
	for (int i=2; i*i<=n; i++) 
	{ 
		if (prime[i]) 
		{ 
			for (int j=i*i; j<=n; j += i) 
				prime[j] = 0; 
		} 
	} 
} 

// Returns the highest exponent of p in n! 
int expFactor(int n, int p) 
{ 
	int x = p; 
	int exponent = 0; 
	while ((n/x) > 0) 
	{ 
		exponent += n/x; 
		x *= p; 
	} 
	return exponent; 
} 

// Returns the no of factors in n! 
ll countFactors(int n) 
{ 
	// ans stores the no of factors in n! 
	ll ans = 1; 

	// Find all primes upto n 
	bool prime[n+1]; 
	sieve(n, prime); 

	// Multiply exponent (of primes) added with 1 
	for (int p=1; p<=n; p++) 
	{ 
		// if p is a prime then p is also a 
		// prime factor of n! 
		if (prime[p]==1) 
			ans *= (expFactor(n, p) + 1); 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 
	int n;
    cin >> n;
	printf("Count of factors of %d! is %lld\n", 
								n, countFactors(n)); 
	return 0; 
}