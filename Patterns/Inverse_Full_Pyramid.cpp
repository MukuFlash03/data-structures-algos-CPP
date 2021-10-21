#include<iostream>
using namespace std;

int main()
{
   int n, i, j;

   cout << "Enter number of rows: ";
   cin >> n;

   for(i = n; i >= 1; i--)
   {
      //for loop to put space
      for(j = i; j < n; j++)
         cout << " ";
      //for loop for displaying star
      for(j = 1; j <= i; j++)
         cout << "* ";

      cout << "\n";
   }

   return 0;
}