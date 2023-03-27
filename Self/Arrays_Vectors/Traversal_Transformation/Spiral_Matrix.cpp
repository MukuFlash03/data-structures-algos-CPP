#include <iostream>
using namespace std;

void printSpiral(int **arr, int m, int n)
{
    int t = 0;
    int b = m-1;
    int l = 0;
    int r = n-1;
    int i,j;
    int dir = 0;

    while (t <= b && l <= r)
    {
        if (dir == 0)
        {
            for (i = l; i <= r; i++)
                cout << arr[t][i] << " ";
            t++;
        }

        if (dir == 1)
        {
            for (i = t; i <= b; i++)
                cout << arr[i][r] << " ";
            r--;
        }

        if (dir == 2)
        {
            for (i = r; i >= l; i--)
                cout << arr[b][i] << " ";
            b--;
        }

        if (dir == 3)
        {
            for (i = b; i >= t; i--)
                cout << arr[i][l] << " ";
            l++;
        }

        dir = (dir+1)%4;
    }
}

int main()
{
    int i, j,m,n;
    cin >> m;
    cin >> n;

    int **arr = new int*[m];
    for (i = 0; i <  m; i++)
        arr[i] = new int[n];

    for (i = 0; i < m; i++) 
      for (j = 0; j < n; j++) 
        cin >> arr[i][j];

    printSpiral(arr,m,n);
    return 0;
}