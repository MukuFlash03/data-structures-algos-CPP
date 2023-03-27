class Solution {
public:
    void reverseString(vector<char>& s) {
        /*for (int i = 0; i < s.size()/2; i++)
            swap(s[i],s[s.size()-i-1]);*/
        int n = s.size();
        int l = 0, r = n-1;
        while (l<r)
            swap(s[l++],s[r--]);
    }
};