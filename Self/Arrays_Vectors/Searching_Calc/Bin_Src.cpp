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

#define F                           first
#define S                           second
#define pb                          push_back
#define mk(arr,n,type)              type *arr = new type[n]
#define fo(i,n)                     for(int i=0; i<n; i++)
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

    ll t;
    cin >> t;
    while(t--)
    {
        ll i,n,q,num,mid,high,low,flag=-1;
        cin >> n >> q;
        //cout << n << "\t" << q << endl;
        vl nums;
        vector <pll> quers;
        fo(i,n)
        {
            cin >> num;
            nums.push_back(num);
        }
        /*fo(i,n)
        {
            cout << nums[i] << "\t";
        }
        pnl(1);*/

        fo(i,q)
        {
            cin >> num;
            quers.push_back(make_pair(num,flag));
            //cout << quers[i].F << "\t" << quers[i].S << endl;
        }

        fo(i,q)
        {

            low = 0;
            high = n-1;
            mid = (high+low)/2;
            /*cout << "High at start:\t" << high << endl;
            cout << "Low at start:\t" << low << endl;
            cout << "Mid at start:\t" << mid << endl;
            pnl(1);*/

            while (high >= low)
            {
               /* cout << "Here!" << endl;
                pnl(1);
                cout << "Mid num:\t" << nums[mid] << "\tKey:\t" << quers[i].F << endl;
                pnl(1);
                */
               
               if (quers[i].F == nums[0])
                {
                    quers[i].S = 0;
                    //cout << "0\n";
                    break;
                }
                if (quers[i].F == nums[n-1])
                {
                    quers[i].S = n-1;
                    //cout << "N-1\n";
                    break;
                }

                if (quers[i].F < nums[mid])
                {
                    //cout << "High before : " << high << endl;
                    high = mid - 1;
                    /*cout << "High after: " << high << endl;
                    cout << "Mid num: " << nums[mid] << endl;
                    cout << "Key: " << quers[i].F << endl;
                    pnl(1);*/
                }
                else if (quers[i].F > nums[mid])
                {
                    //cout << "Low before : " << low << endl;
                    low = mid + 1;
                    /*cout << "Low after: " << high << endl;
                    cout << "Mid num: " << nums[mid] << endl;
                    cout << "Key: " << quers[i].F << endl;
                    pnl(1);*/
                }
                else if (quers[i].F == nums[mid])
                {
                    quers[i].S = mid;
                    //cout << "Key:\t" << quers[i].F << "\tPos:\t" << quers[i].S << endl;
                    break;
                }
                mid = (high+low)/2;
                //cout << "Mid at end:\t" << mid << endl;
                //pnl(1);
            }
        }
        
        fo(i,q)
        {
            cout << quers[i].S << " ";
        }
        cout << endl;
    }
    //cout << endl;
    return 0;
}
