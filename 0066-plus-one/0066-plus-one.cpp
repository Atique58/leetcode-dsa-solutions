class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
      for (int i = digits.size() - 1; i >= 0; i--) 
        {
            // If it's not a 9, just add 1 and we are done!
            if (digits[i] < 9) 
            {
                digits[i]++;
                return digits;
            }
            
            // If it is a 9, it becomes a 0, and the loop carries the 1 left
            digits[i] = 0;
        }
        
        // We only hit this if all digits were 9s (e.g., 99, 999)
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};