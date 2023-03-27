#include <bits/stdc++.h>
using namespace std;

const int N = 100;
bool vis[N] = {};
vector <int> adj_list[N];

void dfs(int node)
{
  vis[node] = 1;
  cout << "Reached node: " << node << endl;

  for (auto i: adj_list[node])
    if (!vis[i])
      dfs(i);
}

int main() 
{
 
  // Number of nodes and edges
  int n = 6, m = 5;
  /*
    We will be adding the 
    following 5 edges.
    (0,1), (0,2), (0,3),
    (2,4), (4,1)
  */
  pair<int, int> edges[] = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {4, 1}};
 
  for (int i = 0; i < m; i++)
  {
    int x = edges[i].first;
    int y = edges[i].second;
    // As graph is undirected
    adj_list[x].push_back(y);
    adj_list[y].push_back(x);
  }
  dfs(0);
 
  return 0;
}