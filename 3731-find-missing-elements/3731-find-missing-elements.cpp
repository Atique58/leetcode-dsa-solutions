class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) 
    {
        vector<int> result;
        int maximum=*max_element(nums.begin(),nums.end());    
		int minimum=*min_element(nums.begin(),nums.end()); 
		unordered_set<int> mp;

        for(int i=0;i<nums.size();i++)
        {
            mp.insert(nums[i]);
        }
		for(int i=minimum;i<=maximum;i++)
		{
			if(mp.find(i)==mp.end())
			{
				result.push_back(i);
			}
		}

		return result;
    }
};