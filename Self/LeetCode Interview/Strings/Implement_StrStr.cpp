class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int k = needle.length();
        int l = haystack.length();
        string sub = "";
        for (int i = 0; i < l - k+1; i++)
        {
            sub = haystack.substr(i,k);
            if (sub == needle)
                return i;
        }
        
        return -1;
    }
};