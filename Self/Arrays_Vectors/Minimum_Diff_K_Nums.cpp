/*****************************
Author: Mukul C. Mahadik
******************************/

/*
https://www.commonlounge.com/discussion/0f4af0958eb449fcb082f6c26c41aece
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef unsigned long long          ull;
typedef string                      str;
typedef pair<ll, ll>                pll;
typedef pair<int, int>              pii;
typedef vector<int>                 vi;
typedef vector<ll>                  vl;
typedef vector<string>              vs;
typedef map<int, int>               mii;
typedef map<ll, ll>                 mll;

#define F                           first
#define S                           second
#define pb                          push_back
#define mk(arr,n,type)              type *arr = new type[n]
#define fo(i,n)                     for(i=0; i<n; i++)
#define pnl(n)                      fo(i,n) {cout << endl;}
#define pi(x)                       printf("%d\n",x)
#define pl(x)                       printf("%ll\n", x)
#define pd(x)                       printf("%lf\n", x)
#define ps(x)                       printf("%s\n", x)
#define si(x)                       scanf("%d", &x)
#define sl(x)                       scanf("%lld", &x)
#define sd(x)                       scanf("%lf\n", &x)
#define ss(x)                       scanf("%s", x)

#define MAX INT_MAX
#define MIN INT_MIN
#define NIL -1
#define gcd __gcd

const int mod = 1000000007;

void fastscan(void)
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void minDiff(vl nums, ll k) 
{ 
    ll diff = MAX;
	sort(nums.begin(), nums.end()); 

	for (int i = 0; i < nums.size()-k; i++)
        diff = min(diff,nums[i+k-1] - nums[i]);
		
    cout << diff << endl;
} 

vl accept_delim_str()
{
	vl temp;
	str str1;
	getline(cin,str1);
	stringstream sstr(str1);

	for(int i; sstr >> i;)
	{
		temp.push_back(i);
		if(sstr.peek() == ' ')
			sstr.ignore();
	}

	return temp;
}

// Driver program 
int main() 
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		cin.ignore(32767, '\n');
		vl temp = accept_delim_str();

		minDiff(temp,k);
	}

	return 0; 
}