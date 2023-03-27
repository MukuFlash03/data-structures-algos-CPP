// Soln 1

class Solution {
    const int NUM_ALPHA = 26;
public:
    vector <int> charFreq(string str)
    {
        vector <int> freq(NUM_ALPHA, 0);
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        for (int i = 0; i < str.length(); i++)
                freq[str.at(i) - 'a']++;
        return freq;
    }
    
public:
    int firstUniqChar(string str) {
        vector <int> freq = charFreq(str);
        
        for (int i = 0; i < str.length(); i++)
            if (freq[str.at(i) - 'a'] == 1)
                return i;
        return -1;
    }
};



// Soln 2

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> chars(26,0);
        for (const char& c : s) {
            chars[c-'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (chars[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};