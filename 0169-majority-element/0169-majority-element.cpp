class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int candidate = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            // If the count drops to zero, we elect a new candidate
            if (count == 0) 
            {
                candidate = nums[i];
            }
            
            // Vote FOR the candidate if it matches, vote AGAINST if it doesn't
            if (nums[i] == candidate) 
            {
                count++;
            }
            else 
            {
                count--;
            }
        }
        
        return candidate;
    }
};