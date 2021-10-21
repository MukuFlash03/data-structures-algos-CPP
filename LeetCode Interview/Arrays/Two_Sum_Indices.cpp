// Soln 1

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes;
        map<int, int> temp;
        
        for(int i=0;i<nums.size();i++){
            nums[i]=target-nums[i];
            temp.insert(pair<int, int>(nums[i], i));
        }
        map<int, int>::iterator it;
        
        for(int i=0;i<nums.size();i++){
            int x=target-nums[i];
            it=temp.find(x);
            if(it!=temp.end()){
                if(it->second<i){
                    indexes.push_back(it->second);
                    indexes.push_back(i);
                    break;
                }else if(it->second>i){
                    indexes.push_back(i);
                    indexes.push_back(it->second);
                    break;
                }
            }
        }
        return indexes;
    }
};

// Soln 2

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector <int> ts;
        vector <int> :: iterator it;
        int diff = 0;
        for (int i = 0; i < n; i++)
        {
            diff = target - nums[i];
            it = find(nums.begin()+(i+1), nums.end(), diff);
            if (it != nums.end())
            {
                ts.push_back(i);
                ts.push_back(it - nums.begin());
                break;
            }
        }
        return ts;
    }
};