/*****************************
Author: Mukul C. Mahadik
******************************/
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
typedef vector <pair<int, int>>     vpii;

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
}


vs accept (int n)
{
    vs nums;
    str strng,word;
    getline(cin,strng);
    stringstream strgstr(strng);
    while(getline(strgstr,word,' '))
        nums.push_back(word);
    return nums;
}

void minUmbrellas (int peeps, vi uSize)
{
    int i=0, nu = uSize.size();
    int rem, count=0, large;
    // int large = *max_element(uSize.begin(), uSize.end());
    // rem = peeps % large;

    fo(i, nu)
    {
        large = uSize[i];
        rem = peeps % large;
        count += floor (peeps/large);
        peeps = rem;
        // cout << peeps << "\t" << large << "\t" << rem << endl;
        if (rem == 0)
            break;
    }

    cout << (rem!=0? -1 : count);
    pnl(1);

}


int main()
{
    fastscan();

    int t;
    cin >> t;
    while (t--)
    {
        int people, umb, temp, i;
        cin >> people >> umb;

        vi uSizes;

        fo(i,umb)
        {
            cin >> temp;
            uSizes.push_back(temp);
        }
        
        sort (uSizes.begin(), uSizes.end(), greater <int>());
        minUmbrellas(people, uSizes);
        // cout << *max_element(uSizes.begin(), uSizes.end()) << endl;
        // cout << *min_element(uSizes.begin(), uSizes.end()) << endl;
    }

    return 0;
}
