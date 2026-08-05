class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int> result;
        unordered_set<int> mp;
        int duplicate;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                duplicate=nums[i];
            }
            mp.insert(nums[i]);
        }
        
        result.push_back(duplicate);
        for(int i=1;i<=nums.size();i++)
        {
            if(mp.find(i)==mp.end())
            {
                result.push_back(i);
            }
        }
        
        return result;
    }
};