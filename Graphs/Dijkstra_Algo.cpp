#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int INF = 1e9;
vector <pair<int,int> > adj_list[N];

int main() 
{
  // Number of nodes and edges
  int n = 5, m = 7;
  vector <int> dist(n,INF);

  //  We will be adding the following 7 edges.
  pair<int, int> edges[] = {{0, 1}, {1, 2}, {2, 4}, {4, 3}, {3, 0}, {3, 1}, {1, 4}};
  int weight[] = {6, 5, 5, 1, 1, 2, 2};

  for (int i = 0; i < m; i++)
  {
    int x = edges[i].first;
    int y = edges[i].second;
    int w = weight[i];
    // As graph is undirected
    adj_list[x].push_back({y,w});
    adj_list[y].push_back({x,w});
  }

  priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

  int src = 0;
  pq.push({0, src}); // {distance from source, source}
  dist[src] = 0;

  cout << "Shortest distance from source vertex " << src << " to " << endl;
  while (!pq.empty())
  {
    int node = pq.top().second;
    pq.pop();

    for (auto i:adj_list[node])
    {
      int v = i.first;
      int w = i.second;
      if (dist[v] > dist[node] + w)
      {
        dist[v] = dist[node] + w;
        pq.push({dist[v], v}); 
      }
    }
  }
 
  for (int i = 0; i < n; i++)
    cout << "Vertex " << i << ": " << dist[i] << endl;

  return 0;
}