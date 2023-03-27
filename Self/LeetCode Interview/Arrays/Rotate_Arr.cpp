class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (k >= n)
            k %= n;
        
        for (int i = 0; i < n-k; i++)
            nums.push_back(nums[i]);
        nums.erase(nums.begin(), nums.begin()+n-k);
        
        for(int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout << endl;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int j = 0; j < k; j++)
        {
            int temp = nums[n-1];
            for(int i = n-1; i >= 1; i--)
                nums[i] = nums[i-1];
            nums[0] = temp;
        }
        for(int i = 0; i<n; i++)
            cout << nums[i] << " ";
        cout << endl;
    }
};