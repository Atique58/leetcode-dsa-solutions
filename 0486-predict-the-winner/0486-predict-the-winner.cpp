class Solution 
{
public:
    bool predictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();
        
        // dp[i][j] stores the max score differential a player can get 
        // from the subarray nums[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base Case: Every subarray of length 1 
        // If there's only one stone, the player just takes it.
        for (int i = 0; i < n; i++) 
        {
            dp[i][i] = nums[i];
        }

        // Build the table up from length 2 all the way to length n
        for (int len = 2; len <= n; len++) 
        {
            // Slide a window of size 'len' across the array
            for (int left = 0; left <= n - len; left++) 
            {
                int right = left + len - 1;
                
                // Option A: Take left stone, subtract opponent's best response
                int pickLeft = nums[left] - dp[left + 1][right];
                
                // Option B: Take right stone, subtract opponent's best response
                int pickRight = nums[right] - dp[left][right - 1];
                
                // Store the best choice for this specific window
                dp[left][right] = max(pickLeft, pickRight);
            }
        }

        // If the score differential for the full array (index 0 to n-1) is >= 0, Player 1 wins
        return dp[0][n - 1] >= 0;
    }
};