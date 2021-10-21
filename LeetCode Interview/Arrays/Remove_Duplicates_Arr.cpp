class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.begin() == nums.end()) return 0;
        int temp = nums[0];
        int ind = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != temp)
            {
                temp = nums[i];
                swap(nums[i],nums[ind]);
                ind++;
            }
        }
        return ind;
    }
};