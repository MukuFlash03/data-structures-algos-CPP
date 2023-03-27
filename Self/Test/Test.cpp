#include<bits/stdc++.h>
using namespace std;

string dpkey = "";
unordered_map <string, int> dp;

char control[4][3] = {
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'},
    {'-', 'J', '-'},
};

bool flag(int a, int b)
{
    if(a < 0 || b < 0 || a >= 4 || b >= 3)
        return false;
    return true;
}

long long solveGame(char control [4][3], int currX, int currY, int currLvl)
    {
        if (currLvl == 0) return 1;
        
        dpkey = "";
        dpkey = to_string(currX) + to_string(currY) + to_string(currLvl);

        if (dp[dpkey] != -1)
            return dp[dpkey];
        
        long long pos = 0;
        int i,nxtX,nxtY;
        int filterX[5] = {0,0,1,0,-1};
        int filterY[5] = {0,1,0,-1,0};

        for(i = 0; i < 5; i++)
        {
            nxtX = filterX[i] + currX;
            nxtY = filterY[i] + currY; 
            if(flag(nxtX,nxtY) and control[nxtX][nxtY] != '-')
                pos += solveGame(control,nxtX,nxtY,currLvl-1);
        }
        return dp[dpkey] = pos;
    }
 
int main()
{
    int n,i,j;
    cin >> n;

    for(i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (int k = 0; k < 16; k++)
            {
                dpkey = to_string(i) + to_string(j) + to_string(n-1);
                dp[dpkey] = -1;
            }
        }
    }

    long long ans = 0;

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(control[i][j] == '-')
                continue;
            ans += solveGame(control,i,j,n-1);
        }
    }
    cout << ans << endl;
}