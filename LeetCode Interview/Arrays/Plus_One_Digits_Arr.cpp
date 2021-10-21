class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector <int> pO;
        int n = digits.size();
        int carry = 0, sum = 0, i;
        sum = digits[n-1] + 1;
        carry = sum / 10;
        digits [n-1] = sum % 10;
        pO.push_back(digits[n-1]);
        for (i = n-2; i >= 0; i--)
        {
            sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;
            pO.push_back(digits[i]);
            if (!carry) break;
        }
        for (int j = i-1; j >= 0; j--)
            pO.push_back(digits[j]);
        
        if (carry) pO.push_back(carry);
        reverse(pO.begin(), pO.end());
        
        return pO;
    }
};