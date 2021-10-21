#include<stdio.h>
char _x_(int,...);
int main()
{
   int i,j,k,m,n;
   i = 9; j =56;k=4;m=78;n=22;
   while(i<=14)
   {
       do
       {
           m = i<j;
           n = m>i;
           k = n*5+m-4;
           j++;
       }
       while(j<=60);
       i++;
   }
       
   printf("%d %d, %d %d %d",i,j,k,m,n);
   return 0;
}