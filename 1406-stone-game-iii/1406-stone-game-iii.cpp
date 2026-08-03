class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) 
        {

            int max_diff = INT_MIN; 
            int current_take = 0;
            
            for (int x = 0; x < 3 && i + x < n; x++)
            {
                current_take += stoneValue[i + x]; 
                max_diff = max(max_diff, current_take - dp[i + x + 1]);
            }
            dp[i] = max_diff;
        }

        if (dp[0] > 0) 
        {
            return "Alice";
        } else if (dp[0] < 0) 
        {
            return "Bob";
        } else 
        {
            return "Tie";
        }
    }
};