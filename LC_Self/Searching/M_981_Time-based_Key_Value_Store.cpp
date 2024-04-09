/*
Type: Binary Search
Problem: https://leetcode.com/problems/time-based-key-value-store
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=fu2cD_6E8Hw
*/


/*

A. Binary Search [O(logn) required]

Can directly run binary search and keeping adding elements to a vector.
This is because, the elements are added in strictly increasing order of timestamp.

 


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class TimeMap {
private:
    map<string, vector<pair<string, int>>> store;
public:
    TimeMap() {
        store.clear();
    }
    
    void set(string key, string value, int timestamp) {
        // if (store.find(key) == store.end()) 
        //     store[key] = vector<pair<string, int>>(); 
        store[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end())
            return "";
    
        int low = 0, high = store[key].size()-1, mid;

        // Best case, latest value is answer
        if (store[key][high].second <= timestamp)
            return store[key][high].first;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (store[key][mid].second == timestamp)
                return store[key][mid].first;
            if (store[key][mid].second < timestamp && store[key][mid+1].second > timestamp)
                return store[key][mid].first;

            if (store[key][mid].second < timestamp)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    TimeMap* obj = new TimeMap();
    obj->set("foo", "bar", 1);
    string res1 = obj->get("foo", 1);
    string res2 = obj->get("foo", 3);
    obj->set("foo", "bar2", 4);
    string res3 = obj->get("foo", 4);
    string res4 = obj->get("foo", 5);

    cout << res1 << '\n';
    cout << res2 << '\n';
    cout << res3 << '\n';
    cout << res4 << '\n';
    cout << '\n';
}