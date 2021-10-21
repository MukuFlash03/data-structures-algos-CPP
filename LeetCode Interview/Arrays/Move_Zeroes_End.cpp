// Soln 1

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        vector <int> pos;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                pos.push_back(nums[i]);
        
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0)
                pos.push_back(0);
        
        for (int i = 0; i < nums.size(); i++)
            nums[i] = pos[i];
    }
};

// Soln 2

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     
        int count = 0;
        int i=0;
        
        while(count<nums.size()){
            
            if(nums[count]!=0){
                swap(nums[count], nums[i]);
                i++;
            }
            count++;
        }
      
    }
};