class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        vector<int> suffix(n, 0);

        // Step 1: Pre-calculate total stones remaining from any index
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // Step 2: The recursive game logic
        auto solve = [&](auto& self, int i, int M) -> int {
            if (i == n)
                return 0; // No stones left

            if (2 * M >= n - i)
                return suffix[i]; // We can take all remaining stones!

            if (dp[i][M] != 0)
                return dp[i][M]; // Already calculated this scenario

            int minOpponentStones = 1e9; // Set to a huge number initially

            // Try taking X stones (from 1 up to 2M)
            for (int X = 1; X <= 2 * M; X++) {
                minOpponentStones =
                    min(minOpponentStones, self(self, i + X, max(M, X)));
            }

            // Our score is the total remaining stones MINUS what the opponent
            // gets
            dp[i][M] = suffix[i] - minOpponentStones;
            return dp[i][M];
        };

        // Start the game at index 0 with M = 1
        return solve(solve, 0, 1);
    }
};