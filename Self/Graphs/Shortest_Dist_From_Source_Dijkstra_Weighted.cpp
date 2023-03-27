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
const int INF = 1e9;

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

int main() 
{
 
  // Number of nodes and edges
  int n, m, i;
  cin >> n >> m;

  vpii adj_list[n];
  pii edges[m];
  vi dist(n,INF);
  int weight[m];


  fo(i,m)
  {
      cin >> edges[i].F >> edges[i].S >> weight[i];
  }
 
  fo(i,m)
  {
    int x = edges[i].F;
    int y = edges[i].S;
    int w = weight[i];

    // As graph is undirected
    adj_list[x].push_back({y,w});
    adj_list[y].push_back({x,w});
  }

  priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

  int src = 0;
  pq.push({0, src}); // {distance from source, source}
  dist[src] = 0;

  while (!pq.empty())
  {
    int node = pq.top().S;
    pq.pop();
    
    for (auto i:adj_list[node])
    {
      int v = i.F;
      int w = i.S;
      if (dist[v] > dist[node] + w)
      {
        dist[v] = dist[node] + w;
        pq.push({dist[v], v}); 
      }
    }
  }


  cout << dist[0] << " ";
  for(i = 1; i < n; i++)
  {
      if (dist[i] == INF)
        cout << "INF" << " ";
      else
        cout << dist[i] << " ";
  }
  pnl(1);

  return 0;
}