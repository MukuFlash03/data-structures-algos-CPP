/*

Problem: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
Solution(s): 

YouTube
NC - 
*/


/*

A. Optimal Solution 



*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int countCharacters(vector<string>& words, string chars) {

    /*
    // M1: Sort + Pointers
    sort(chars.begin(), chars.end());
    cout << chars << "\n";

    for (auto& elem : words) 
        sort(elem.begin(), elem.end());

    int ptr1, ptr2;
    int sum = 0;
    int wordSize, charsSize = chars.length();
    bool flag = false;

    for (const auto& elem : words) {
        ptr1 = 0, ptr2 = 0;
        wordSize = elem.length();
        for (int i = 0; i < wordSize; i++) {
            if (elem[ptr1] == chars[ptr2]) {
                ptr1++;
                ptr2++;
            }
            while (elem[ptr1] > chars[ptr2]) {
                ptr2++;
            }
            cout << ptr1 << "\t" << ptr2 << "\n";
        }
        cout << elem << "\t" << ptr1 << "\t" << wordSize << "\n";
        if (ptr1 == wordSize) {
            sum += wordSize;
            cout << elem << "\t" << ptr1 << "\t" << wordSize << "\n";
        }
            
    }
    
    return sum;

    */

    /*  
    deeehllnn_oorwy
    ehll_o


    */

    // M2: FreqMap
    map<int, int> freqMap_1;
    map<int, int> freqMap_2;
    int sum = 0;
    bool flag = false;

    for (const auto& ch : chars)
        freqMap_2[ch - 'a']++;

    for (const auto& elem : words) {
        for (const auto& ch : elem)
            freqMap_1[ch - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (freqMap_1[i] > freqMap_2[i]) {
                flag = false;
                break;
            }
            else
                flag = true;
        }
        
        if (flag) 
            sum += elem.length();

        for (int i = 0; i < 26; i++) {
            freqMap_1[i] = 0;
        }
    }

    return sum;
}

int main() {

    // vector<string> words = {"cat","bt","hat","tree"};
    // string chars = "atach";

    vector<string> words = {"hello","world","leetcode"};
    string chars = "welldonehoneyr";

    int sumLength = countCharacters(words, chars);
    cout << sumLength << "\n";


    return 0;
}