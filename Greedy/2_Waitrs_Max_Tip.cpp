/*****************************
Author: Mukul C. Mahadik
******************************/


/* Question
https://www.codechef.com/problems/TADELIVE
https://discuss.codechef.com/t/tadelive-editorial/8871
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef unsigned long long          ull;
typedef pair<ll, ll>                pll;
typedef pair<int, int>              pii;
typedef vector<int>                 vi;
typedef vector<ll>                  vl;
typedef map<int, int>               mii;

#define F                          first
#define S                          second
#define pb                          push_back
#define mk(arr,n,type)              type *arr = new type[n]
#define fo(i,n)                     for(i=0; i<n; i++)
#define pnl(i,n)                    fo (i,n){printf("\n");}
#define pi(x)                       printf("%d\n",x)
#define pl(x)                       printf("%ll\n",x)
#define pd(x)                       printf("%lf\n",x)
#define ps(x)                       printf("%s\n",x)
#define si(x)                       scanf("%d",&x)
#define sl(x)                       scanf("%lld",&x)
#define sd(x)                       scanf("%lf\n",&x)
#define ss(x)                       scanf("%s",x)

#define MAX INT_MAX
#define MIN INT_MIN
#define NIL -1
#define gcd __gcd

const int mod = 1000000007;

int mpow(int base, int exp);

void fastscan(void)
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


int main()
{
    fastscan();
    ll n,x,y,i,ind, ao=0, bo=0, totalTipMoney=0;
    vector <pll> diff;
    //si(n); si(x); si(y);
    cin >> n >> x >> y;
    vl A(n), B(n);

    //mk(A,n,ll);
    fo(i,n)
    {
        cin >> A[i];
    }
    //mk(B,n,ll);
    fo(i,n)
    {
        cin >> B[i];
    }

    fo(i,n)
    {
        diff.push_back(make_pair(abs(A[i]-B[i]),i));
    }

    sort(diff.begin(),diff.end());
    reverse(diff.begin(),diff.end());

    fo(i,n) 
    {
        ind = diff[i].second;
	    if (A[ind] > B[ind])
        {
		    if (ao + 1 <= x)
            {
			    ao++;
			    totalTipMoney += A[ind];
		    } 
            else 
            {
			    bo++;
			    totalTipMoney += B[ind];
		    }
	    } 
        else 
        {
		    if (bo + 1 <= y)
            {
			    bo++;
			    totalTipMoney += B[ind];
		    } 
            else
            {
			    ao++;
			    totalTipMoney += A[ind];
		    }
	    }  
    }
    cout << totalTipMoney << endl;
    return 0;
}
