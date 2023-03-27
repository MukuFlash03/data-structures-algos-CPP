class Solution {
public:
    int rob(vector<int>& nums) {

        int i, n = nums.size();
        int ppMax, pMax, cMax;
        ppMax = pMax = cMax = 0;
        for (i = 0; i < n; i++)
        {
            cMax = pMax;
            cMax = max(cMax, nums[i] + ppMax);
            ppMax = pMax;
            pMax = cMax;
        }

        return cMax;

    }
};