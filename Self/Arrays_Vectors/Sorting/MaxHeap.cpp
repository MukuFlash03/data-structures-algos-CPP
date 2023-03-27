/*****************************
Author: Mukul C. Mahadik
******************************/
/*
https://www.hackerearth.com/practice/notes/heaps-and-priority-queues/
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


vl minHeapify(vl nums, ll i)
{
    ll N = nums.size();
    ll left = 2*i + 1;
    ll right = 2*i + 2;
    ll largest = i;
    
    if (left <= N && nums[left] > nums[largest])
        largest = left;
    if (right <= N && nums[right] > nums[largest])
        largest = right;

    if (largest != i)
    {
        swap (nums[i], nums[largest]);
        nums = minHeapify(nums, largest);
    }
    return nums;
}

vl buildMinHeap (vl nums)
{
    for(int i = nums.size()/2 - 1; i >= 0; i--)
        nums = minHeapify(nums,i);

    return nums;
}

int main()
{
    fastscan();
    ll size, num, i;
    cin >> size;
    vl nums, temp;
    fo(i,size)
    {
        cin >> num;
        nums.push_back(num);
    }

    temp = buildMinHeap(nums);
    
    fo(i,size)
    {
        cout << temp[i] << "\t";
    }
    pnl(1);
    return 0;
}
