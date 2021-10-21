// Soln 1
// https://www.tutorialcup.com/interview/string/longest-common-prefix-using-sorting.htm-

#include<bits/stdc++.h> 
using namespace std; 
// function to return the longest common prefix from the array of strings 
string longestCommonPrefix(string arr[], int n) 
{ 
  // If size is 0, return empty string 
    if (n == 0) 
        return ""; 
        
    // if only one string is present in the array
    // it itself is the prefix
    if (n == 1) 
        return arr[0]; 
  
    // Sort the array of strings 
    sort(arr, arr + n); 
    
    // first string of the array has minimum length
    int min = arr[0].length();
    
    // common prefix of the whole array
    // is common prefix of first and last strings
    string first = arr[0], last = arr[n - 1]; 
    
    // recur until strings have common characters
    int i = 0; 
    while (i < min && first[i] == last[i]) 
        i++; 
  
    string prefix = first.substr(0, i); 
    return prefix;
} 
// main program to implement above <a href="https://www.tutorialcup.com/cplusplus/functions.htm">functions</a> 
int main() 
{ 
  string arr[] = {"tutorialcup", "tutorial", "tussle", "tumble"}; 
  int n = sizeof (arr) / sizeof (arr[0]); 
  string ans = longestCommonPrefix(arr, n); 
  if (ans.length()) 
    cout << "Longest common prefix = "<< ans; 
  else
    cout << "no common prefix found";
    
  return 0; 
}


// Soln 2
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int i, j, n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];
        sort(strs.begin() ,strs.end());
        for (j = 0; j < strs[0].size() && j < strs[n - 1].size() && strs[0][j] == strs[n - 1][j]; j++);
        return strs[0].substr(0, j);
    }
};