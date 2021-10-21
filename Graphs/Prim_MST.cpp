#include <bits/stdc++.h>
using namespace std;

int vis[1001];
int main() 
{
  int n = 5, m;
  vector<pair<int, int> >graph[n];
  vector<pair<int, int> >mst;

  pair<int, int>edges[] = { {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}, {1, 4}, {1, 3} };
  int weight[] = {1, 4, 2, 6, 7, 5, 3};
  
  m = sizeof(weight) / sizeof(weight[0]);
 
  // Build the adjacency list
  for(int i = 0; i < m; i++)
  {
    graph[edges[i].first].push_back({edges[i].second, weight[i]});
    graph[edges[i].second].push_back({edges[i].first, weight[i]});
  }
  /*
    priority queue in cpp is
    max heap by default. We need 
    min heap for prim's algorithm.
    We store (weight, (u, v))
  */
  priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >,greater< pair<int, pair<int, int> > > >pq;
  /*
    We can start with any random node.
    WLOG we start with node 0
  */
  for(auto i: graph[0])
    pq.push({i.second, {i.first, 0}});
  vis[0] = 1;
  int cost = 0;
  while(!pq.empty())
  {
    // get minimum-weight edge to an unvisited node from heap
    // pq.top() gives the (weight,(node,previousnode)) with min weight priority
    int w = pq.top().first;
    int node = pq.top().second.first;
    int previousnode = pq.top().second.second;
    pq.pop();   
 
    // already visited 
    if(vis[node])continue;
    
    // found new reachable node. Mark visited and update MST
    vis[node] = 1;
    cost += w;
    mst.push_back({node, previousnode});
 
    // add all edges from this node to the heap
    for(auto i: graph[node])
      pq.push({i.second, {i.first, node}});
  }
  cout << "Minimum cost of spanning tree is: " << cost << endl;
  cout << "Following are the edges in MST: " << endl;
  for(auto i: mst)
    cout << i.first << " " << i.second << endl;
  return 0;
}