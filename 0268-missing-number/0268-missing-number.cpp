class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        
        // Calculate what the perfect sum should be
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        
        // Add up the numbers we actually have
        for (int i = 0; i < n; i++) 
        {
            actualSum += nums[i];
        }
        
        // The difference is our missing number
        return expectedSum - actualSum;
    }
};