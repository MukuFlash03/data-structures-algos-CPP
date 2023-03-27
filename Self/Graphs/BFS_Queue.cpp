#include <bits/stdc++.h>
using namespace std;

const int N = 100;
// bool vis[N] = {};
pair <bool, long> vis[N];
int parent[N];
vector <int> adj_list[N];

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
  
  queue <int> q;
  q.push(0);    // add first node 0
  vis[0].first = 1;   // and mark it as visited
  vis[0].second = 0; // set length of path for source node = 0
  parent[0] = -1; // set parent of source node as none = -1

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    cout << "Visited node: " << node << endl;

    for (auto i:adj_list[node])
    {
      if (!vis[i].first)
      {
        q.push(i);
        vis[i].first = 1;
        vis[i].second = vis[node].second + 1; //calculating path length
        parent[i] = node;
        // cout << "Length of path for node " << i << ":\t" << vis[i].second << endl;
        // cout << "Parent of node " << i << ":\t" << parent[i] << endl;
      }
    }
  }

  return 0;
}