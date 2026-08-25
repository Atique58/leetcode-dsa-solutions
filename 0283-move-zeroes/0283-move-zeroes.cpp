class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int insertPosition = 0;
        
        // Step 1: Pull every non-zero number to the front of the array
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] != 0) 
            {
                nums[insertPosition] = nums[i];
                insertPosition++;
            }
        }
        
        // Step 2: Fill the rest of the array with zeroes
        while (insertPosition < nums.size()) 
        {
            nums[insertPosition] = 0;
            insertPosition++;
        }
    }
};