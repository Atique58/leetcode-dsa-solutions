class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) 
        {
            // Calculate mid this way to prevent integer overflow
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) 
            {
                return mid; // Found it!
            }
            else if (nums[mid] < target) 
            {
                left = mid + 1; // Target is bigger, search right half
            }
            else 
            {
                right = mid - 1; // Target is smaller, search left half
            }
        }
        
        return -1; // Never found it
    }
};