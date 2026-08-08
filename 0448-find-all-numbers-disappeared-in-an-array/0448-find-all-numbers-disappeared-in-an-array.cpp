class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> ans;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        } 
		for(int i=0;i<nums.size();i++)
		{
			if(st.find(i+1)==st.end())
			{
				ans.push_back(i+1);
			}
		}
        return ans;
    }
};