#include <iostream>
#include <bits/stdc++.h>
using namespace std;


float x[11]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
float y[11]= {0, 10, 25, 35, 40, 53, 60, 75, 80, 93, 100};
float m[10] = {0,0,0,0,0,0,0,0,0,0};
float c[10] = {0,0,0,0,0,0,0,0,0,0};
int i;

void interpolate(float x[], float y[])
{
    for (i=0; i<10; i++)
    {
        m[i] = (y[i+1] - y[i]) / (x[i+1] - x[i]);
        c[i] = y[i] - m[i]*x[i];
    }
}

/*
float sensor3vtot(float vin)
{
    float tout,m,c;
    
    if (vin >= 0 && vin <= 1)
    {
        m = 
    }
   
}
*/

int main(int argc, char** argv)
{
    float v=0,t=0;

    interpolate(x,y);
    cout << "m and c values are:" << endl;
    for (i=0; i<10; i++)
        cout << m[i] << ", " << c[i] << endl;

return 0;
}