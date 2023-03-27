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


bool compareInterval(pll i1, pll i2) 
{ 
	return (i1.S < i2.S) ? true : false; 
} 

// Function to check if any two intervals overlap 
bool isOverlap(vector <pll> nums) 
{ 
	// Sort intervals in increasing order of start time 
	sort(nums.begin(), nums.end(), compareInterval); 
	
	/*int i;
	fo(i,nums.size())
	{
		cout << nums[i].F << "\t" << nums[i].S << endl;
	}
	*/

	// In the sorted array, if start time of an interval 
	// is less than end of previous interval, then there 
	// is an overlap 
	for (int i = 1; i < nums.size(); i++) 
		if (nums[i - 1].S >= nums[i].F) 
			return true; 

	// If we reach here, then no overlap 
	return false; 
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
		if(sstr.peek() == ' ' || sstr.peek() == ',')
			sstr.ignore();
	}

	return temp;
}

// Driver program 
int main() 
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cin.ignore(32767, '\n');
		vl temp = accept_delim_str();

		vector <pll> nums;
		for(int i = 0; i < temp.size(); i +=2)
		{
			nums.push_back(make_pair(temp[i],temp[i+1]));
		}

		/*
		int i;
		fo(i,nums.size())
		{
			cout << nums[i].F << "\t" << nums[i].S << endl;
		}*/

		isOverlap(nums) ? cout << "Yes\n" : cout << "No\n"; 
	}

	return 0; 
}