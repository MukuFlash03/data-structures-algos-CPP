class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "")
            return true;
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string word = "";
        for (int i = 0; i < s.length(); i++)
            if (isalpha(s[i]) || isdigit(s[i]))
                word += s.at(i);
        
        int l = word.length();
        for (int i = 0; i < l/2; i++)
            if (word[i] != word[l-i-1])
                return false;
        cout << word << endl;
        return true;
    }
};