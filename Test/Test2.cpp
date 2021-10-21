#include<bits/stdc++.h>
typedef long int ll;
#define pb push_back
#define db cout << 'hi' << endl;
#define trip pair<ll,pair<ll,ll> >
#define pi pair<ll,ll>
#define MAXX std::numeric_limits<ll>::max()
#define MINN std::numeric_limits<ll>::min()
using namespace std;

ll dp[4][3][16];

bool check(int a, int b)
    {
    if(a < 0 or b<0 or a>=4 or b>= 3)
        return false;
    return true;
    }

ll dfs(int cx, int cy, char board [4][3], int lvl)
    {
    if(lvl==0)
        return 1;
    
    //else
    if(dp[cx][cy][lvl] != -1)
        return dp[cx][cy][lvl];
    //else
    ll me = 0;
    int x[5] = {0,0,1,0,-1};
    int y[5] = {0,1,0,-1,0};
    for(int k = 0 ; k<5 ; k++)
        {
        int nx = cx + x[k];
        int ny = cy + y[k]; 
        if(check(nx,ny) and board[nx][ny] != '-')
            {
            me += dfs(nx,ny,board,lvl-1);
            }
        }
    return dp[cx][cy][lvl] = me;
    }
 
int main()
{
char board[4][3] = {
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'},
    {'-', 'J', '-'},
};
int res = 0;
int n; cin >> n;

memset(dp, -1, sizeof(dp));
for(int i = 0 ; i<4 ; i++)
    {
    for(int j = 0 ; j<3 ; j++)
        {
        if(board[i][j] == '-')
            continue;
        res += dfs(i,j,board,n-1);
        }
    }
cout << res << endl;
}