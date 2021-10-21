#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int t;
	cin >> t;
	while (t > 0)
	{
        long long int a,b;
        cin >> a >> b;
        cout << __gcd(a,b) << endl;
	    t--;
	}
	return 0;
}