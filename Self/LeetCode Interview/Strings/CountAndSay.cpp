class Solution {
public:
    string countAndSay(int n) {
        /*
        if (n == 1) return "1";
        
        string str = countAndSay(n-1);
        string res = "";
        vector <int> freq(9,0);
        
        for (int i = 0; i < str.length(); i++)
            freq[str[i]-'0']++;
        
        for (int i = 0; i < str.length(); i++)
        {
            if (freq[str[i]-'0'] != 0)
            {
                cout << freq[str[i]-'0'] << str[i] << endl;
                res += to_string(freq[str[i]-'0']) + str[i];
                /*for (int j = 0; j < freq[str[i]-'0']; j++)
                    res += str[i];
            }
        }*/
    
    if (n == 1) return "1";
    string res = "";
    string s = countAndSay(n - 1);
    int len = s.length();
    int i = 0;
    while (i < len) {
        int count = 1;
        char ch = s.at(i++);
        while (i < len && s.at(i) == ch) {
            ++count;
            ++i;
        }
        res = res + to_string(count) + ch;
    }
        
        return res;
    }
};