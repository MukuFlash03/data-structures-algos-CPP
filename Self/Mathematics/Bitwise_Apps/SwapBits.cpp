// C++ Program to swap bits 
// in a given number 
#include <bits/stdc++.h> 
using namespace std; 

int swapBits(unsigned int x, unsigned int p1, 
			unsigned int p2, unsigned int n) 
{ 
	/* Move all bits of first set to rightmost side */
	unsigned int set1 = (x >> p1) & ((1U << n) - 1); 

	/* Move all bits of second set to rightmost side */
	unsigned int set2 = (x >> p2) & ((1U << n) - 1); 

	/* Xor the two sets */
	unsigned int Xor = (set1 ^ set2); 

	/* Put the Xor bits back to their original positions */
	Xor = (Xor << p1) | (Xor << p2); 

	/* Xor the 'Xor' with the original number so that the 
	two sets are swapped */
	unsigned int result = x ^ Xor; 

	return result; 
} 

/* Driver code*/
int main() 
{ 
	int num, b1, b2, nb;
    cin >> num >> b1 >> b2 >> nb;
    int res = swapBits(num, b1, b2, nb); 
	cout << "Result = " << res << endl; 
	return 0; 
}

/*
1) Move all bits of the first set to the rightmost side
   set1 =  (x >> p1) & ((1U << n) - 1)
Here the expression (1U << n) - 1 gives a number that 
contains last n bits set and other bits as 0. We do & 
with this expression so that bits other than the last 
n bits become 0.
2) Move all bits of second set to rightmost side
   set2 =  (x >> p2) & ((1U << n) - 1)
3) XOR the two sets of bits
   xor = (set1 ^ set2) 
4) Put the xor bits back to their original positions. 
   xor = (xor << p1) | (xor << p2)
5) Finally, XOR the xor with original number so 
   that the two sets are swapped.
   result = x ^ xor
*/