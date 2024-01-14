#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

string getSubEncryptedString(vector<string> message) {
    int n = message.size();
    int k = message[0].size();
    vector<vector<int>> errorMap(26,vector<int>(k,0));
    vector<int> charMap(k);

    for (const auto& elem : message) {
        for (int i = 0; i < 26; i++) {
            charMap.clear();
            for (int j = 0; j < k; j++) {
                errorMap[i][j] += abs(elem[j] - ('a' + i));
            }
        }
    }
    
    string ans = "";
    int end = k - 1;
    int mins = INT_MAX, store=0;
   
    for(int start = 0; start <= k/2; start++)
    {
        for(int i = 0; i < 26; i++)
        {
            if(start == end)
            {
                if(mins > errorMap[i][start])
                {
                    store = i;
                    mins = errorMap[i][start];
                }
            }
            else if(mins > errorMap[i][start] + errorMap[i][end]) 
            {
                store = i;
                mins = errorMap[i][start] + errorMap[i][end];
            }
        }
        mins = INT_MAX;
        end--;
        ans += (store + 'a');
    }

    string temp = ans.substr(0, k-ans.size());
    reverse(temp.begin(), temp.end());
    // for(const auto& elem : temp) 
    //     ans = ans + elem;
    ans = ans + temp;
    
    return ans;
}


int main() {
    // vector<string> str = {"aba", "cbd"};
    // vector<string> str = {"abc", "cdf"};
    vector<string> str = {"aa", "yy", "mm"};
    cout << getSubEncryptedString(str) << '\n';
    return 0;
}