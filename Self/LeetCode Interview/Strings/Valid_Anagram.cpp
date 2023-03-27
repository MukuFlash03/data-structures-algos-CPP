class Solution {
    
const int NUM_ALPHA = 26;
    
public:    
    vector <int> charFreq(string str)
    {
        vector <int> freq(NUM_ALPHA,0);
        for (int i = 0; i < str.length(); i++)
            freq[str.at(i)-'a']++;
        return freq;
    }

public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length())
            return false;
        
        vector <int> f1 = charFreq(s);
        vector <int> f2 = charFreq(t);
        
        for (int i = 0; i < s.length(); i++)
            if (f1[s.at(i)-'a'] != f2[s.at(i)-'a'])
                return false;
        
        return true;
        
    }
};