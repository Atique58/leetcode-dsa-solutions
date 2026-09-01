class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // Edge case: empty array
        if (nums.size() == 0) 
        {
            return 0;
        }
        
        int insertPosition = 1;
        
        for (int i = 1; i < nums.size(); i++) 
        {
            // If it's not a duplicate of the previous number, keep it
            if (nums[i] != nums[i - 1]) 
            {
                nums[insertPosition] = nums[i];
                insertPosition++;
            }
        }
        
        // The insertPosition also naturally counts how many unique numbers we found
        return insertPosition;
    }
};