class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return false;
        sort(nums.begin(), nums.end());
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != temp)
                temp = nums[i];
            else return true;
        }
        return false;
    }
};