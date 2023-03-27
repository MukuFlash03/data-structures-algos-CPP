#include <bits/stdc++.h>
using namespace std;
int main() 
{
 
  int n, m;
  // Number of nodes
  n = 6;
  // Number of edges
  m = 5; 
 
  int adj_matrix[n][n];
  // Initialising all values equal to 0
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      adj_matrix[i][j] = 0;
 
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
    adj_matrix[x][y] = adj_matrix[y][x] = 1; //undirected graph; for directed only [x][y] = 1
  }
 
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << adj_matrix[i][j] << " "; 
    cout << endl;
  }
  return 0;
}