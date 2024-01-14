/*
Problem: https://leetcode.com/problems/encode-and-decode-strings/
Solution(s): 
    
YouTube
NC - https://www.youtube.com/watch?v=B1k_sxOSgv8
*/


/*



*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

string encode(vector<string>& strs) {
    char encodingChar = '#';
    string encoded = "";
    
    for (const auto& elem : strs) {
        encoded += to_string(elem.size()) + encodingChar + elem;
    }

    return encoded;
}

vector<string> decode(string s) {
    vector<string> decoded;
    char encodingChar = '#';
    string temp = "";
    int len = 0;
    int i  = 0, j = 0;

    while (i < s.size()) {
        j = i;
        while (s[j] != encodingChar) {
            j++;
        }
        len = stoi(s.substr(i, j - i));
        temp = s.substr(j + 1, len);
        decoded.push_back(temp);
        i = j + len + 1;
    }
    return decoded;
}

int main() {

    // vector<string> strs = { "Hello", "World", "How", "Are", "You" };
    vector<string> strs = {"neet","code","love","you"};
    // vector<string> strs = {"we","say",":","yes"};

    string encoded = encode(strs);
    cout << encoded << '\n';
    vector<string> decoded = decode(encoded);
    for (const auto& elem : decoded)
        cout << elem << '\n';

    return 0;
}