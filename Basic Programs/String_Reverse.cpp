#include <bits/stdc++.h> 
using namespace std; 
  
//Using swap(ch1,ch2) to swap characters 
void reverseStr(string& str) 
{ 
    int n = str.length(); 
  
    // Swap character starting from two 
    // corners 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 

void reverse_simple(string str) 
{ 
   for (int i=str.length()-1; i>=0; i--) 
      cout << str[i];  
    cout << "\n";
} 
  
// Driver program 
int main() 
{ 
    string str = "geeksforgeeks";
    string str1 = "geeksforgeeks";
    string str2 = "geeksforgeeks";

    //Using swap(ch1,ch2) to swap characters
    reverseStr(str2);
    cout << "\n" << str2 << "\n";

    //Using reverse(str[begin..end]) inbuilt function 
    reverse(str1.begin(), str1.end());
    cout << "\n" << str1 << "\n";

    //Using for loop (brute force)
    cout << "\n";
    reverse_simple(str);

    return 0; 
} 