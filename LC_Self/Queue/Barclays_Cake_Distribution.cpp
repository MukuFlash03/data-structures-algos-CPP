/*

Barclays OA
Cake Distribution
Number of slices = N*M
Number of people = K
Next K lines, K list of choices
Example:
1 2 3
2
1

Example:
1 2 3
1 2 3
1 2 3
1 2 6
1 5 6

Example:
2 3
2 3
3 4

Example:
2 3
2 3
2 3
*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_set>
#include<map>
#include<set>

using namespace std;

// void printMap(map<int, vector<int>> choiceMap)  {
//     for (const auto& choice : choiceMap) {
//         cout << choice.first << ": ";
//         for (const auto& person: choice.second)
//             cout << person << " ";
//         cout << endl;
//     }
// }

// void printSet(multiset<pair<int, int>> choiceSet)  {
//     for (const auto& choice : choiceSet) {
//         cout << choice.first << ": " << choice.second << endl;
//     }
// }

void createChoiceMap(map<int, vector<int>>& choiceSlices, vector<vector<int>>& friends) {
    for (int i = 0; i < friends.size(); i++) {
        for (const auto choice : friends[i]) {
            choiceSlices[choice].push_back(i);
        }
    }
}

void createChoiceSet(multiset<pair<int, int>>& sortedFriendsSize, map<int, vector<int>> choiceSlices) {
    for (const auto& choiceFriends : choiceSlices) {
        sortedFriendsSize.insert({choiceFriends.second.size(), choiceFriends.first});
    }
}

bool compareChoices(vector<int> a, vector<int> b) {
    if (a.size() == b.size())
        return a[0] < b[0];
    return a.size() < b.size();
}

// bool compareFriendSize(pair<int, int> a, pair<int, int> b) {
//     return a.second < b.second;
// }

int cakeDistribute(vector<vector<int>>& friends, pair<int, int> size) {
    int k = friends.size();
    int n = size.first;
    int m = size.second;
    int totalSlices = n * m; 
    int happy = 0;
    int key;

    sort(friends.begin(), friends.end(), compareChoices);

    map<int, vector<int>> choiceSlices;
    createChoiceMap(choiceSlices, friends);

    multiset<pair<int, int>> sortedFriendsSize;
    createChoiceSet(sortedFriendsSize, choiceSlices);


    while (!sortedFriendsSize.empty()) {
        const auto choiceSize = *sortedFriendsSize.begin();
        key = choiceSize.second;

        choiceSlices[key].erase(choiceSlices[key].begin());
        sortedFriendsSize.erase(sortedFriendsSize.begin());

        happy++;

        for (auto& choiceFriends : choiceSlices) {
            if (choiceFriends.second.size() == 0)
                continue;

            auto it = std::find(choiceFriends.second.begin(), choiceFriends.second.end(), key);

            if (it != choiceFriends.second.end()) {
                choiceFriends.second.erase(it);
            }
        }
    }

    return happy;
}


int main() {

    // vector<vector<int>> choices = {{1,2,3}, {2}, {1}};
    // pair<int, int> cakeSize = {2, 2};

    // vector<vector<int>> choices = {{1,2,3}, {1,2,3}, {1,2,3}, {1,2,6}, {1,5,6}};
    // pair<int, int> cakeSize = {2, 3};
    
    // vector<vector<int>> choices = {{2,3}, {2,3}, {3, 4}};
    // pair<int, int> cakeSize = {2, 2};

    vector<vector<int>> choices = {{2,3}, {2,3}, {2, 3}};
    pair<int, int> cakeSize = {2, 2};


    int happy = cakeDistribute(choices, cakeSize);
    cout << happy << "\n";

    return 0;
}