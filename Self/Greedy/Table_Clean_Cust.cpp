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

#define F                           first
#define S                           second
#define pb                          push_back
#define mk(arr,n,type)              type *arr = new type[n]
#define fo(i,n)                     for(i=0; i<n; i++)
#define pnl                         printf("\n");
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

    int t;
    cin >> t;

    while (t--)
    {
        int n,m,c,i,occup=0,clean=0,;
        cin >> n >> m;
        
        vector <pii> cust;
        vi no;
        fo(i,m)
        {
            cin >> c;
            cust.push_back(make_pair(c,i));
        }

        fo(i,m)
        {
            if (occup != n)
            {
                if (cust[i].F != cust[i].end())
                no.push_back(c);
                occup++;
            }




    }



    

    return 0;
}
