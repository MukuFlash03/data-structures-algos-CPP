class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int i, n = nums.size();
        long long currMax, prevMax = INT_MIN;
        long long ans = INT_MIN;
        for (i = 0; i < n; i++)
        {
            currMax = nums[i];
            currMax = max(currMax, currMax + prevMax);
            ans = max(ans,currMax);
            prevMax = currMax;
        }
        return ans;
    }
};