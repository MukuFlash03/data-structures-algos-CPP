#include <bits/stdc++.h>
using namespace std;
int main() 
{
 
  // Number of nodes (n) and edges (m)
  int n, m;
  n = 6;
  m = 5; 
 
  vector<int>adj_list[n];
 
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
    // As graph is undirected; for directed only [x].push_back(y)
    adj_list[x].push_back(y);
    adj_list[y].push_back(x);
  }
 
  for (int i = 0; i < n; i++)
  {
    cout << "Edges connected to " << i <<" vertex are: ";
    for (int j = 0; j < adj_list[i].size(); j++)
      cout << adj_list[i][j] << " "; 
    cout << endl;
  }
 
  return 0;
}