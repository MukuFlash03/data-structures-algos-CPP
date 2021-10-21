/*
https://www.tutorialcup.com/interview/string/shortest-palindrome.htm
*/

#include<bits/stdc++.h> 
using namespace std; 
  
bool isPalindrome(string s){ 
    int l = s.length(); 
    int j; 
      
    for(int i=0, j=l-1; i<=j; i++, j--){ 
        if(s[i] != s[j]) 
            return false; 
    } 
    return true; 
} 
  
int main(){ 
    string s = "abc"; 
    int count = 0, f = 0; 
      
    while(s.length()>0){ 
        if(isPalindrome(s)){ 
            f = 1; 
             break; 
        } 
        else{ 
            count++; 
            s.erase(s.begin() + s.length() - 1); 
        } 
    } 
      
    if(f) 
        cout<<count; 
}