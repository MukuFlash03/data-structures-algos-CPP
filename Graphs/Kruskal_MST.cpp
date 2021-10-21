#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>rt, sz;
vector<pair<int, int> >mst;
void init()
{
  /*
    Initialises the root of every
    node as itself and size 
    disjoint set as 1
  */
  for (int i = 0; i < n; i++)
  {
    rt[i] = i;
    sz[i] = 1;
  }
}
 
int root(int i)
{
  while(i != rt[i])
  {
    rt[i] = rt[rt[i]];
    i = rt[i];
  }
  return i;
}
 
void join(int a, int b)
{
  int rta = root(a);
  int rtb = root(b);
  int sza = sz[rta];
  int szb = sz[rtb];
  /*
    To merge the sets, we can simply do parent[root(u)] = root(v).
    To ensure that tree heights are O(log n), we make the root of 
    the smaller tree a child of the root of the larger tree.
    (since a node's root can't change more than log n times)
   */
  if(sza >= szb)
  {
    rt[rtb] = rt[rta];
    sz[rta] += sz[rtb];
    sz[rtb] = 0;
  }
  else
  {
    rt[rta] = rt[rtb];
    sz[rtb] += sz[rta];
    sz[rta] = 0;
  }
}
int main() 
{
  n = 5;
  pair<int, int>edges[] = { {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}, {1, 4}, {1, 3} };
  int weight[] = {1, 4, 2, 6, 7, 5, 3};
  m = sizeof(weight) / sizeof(weight[0]);
  rt.resize(n);
  sz.resize(n);
  init();
  vector<pair<int, int> >v;
  for (int i = 0; i < m; i++)
  {
    v.push_back({weight[i], i});
  }
  // sorts in ascending order of weights of edges
  sort(v.begin(), v.end());
  int cost = 0;
  for (int i = 0; i < m; i++)
  {
    int idx = v[i].second;
    /* If the two nodes are in disjoint sets
       then the roots would be different, in which
       case we join the two nodes
    */
    if (root(edges[idx].first) != root(edges[idx].second))
    {
      join(edges[idx].first, edges[idx].second);
      cost += v[i].first;
      mst.push_back({edges[idx].first, edges[idx].second});
    }
  }
  cout << "Minimum cost of spanning tree is: " << cost << endl;
  cout << "Following are the edges in MST: " << endl;
  for(auto i: mst)
    cout << i.first << " " << i.second << endl;
  return 0;
}