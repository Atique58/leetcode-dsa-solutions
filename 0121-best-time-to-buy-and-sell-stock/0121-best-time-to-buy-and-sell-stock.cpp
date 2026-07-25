class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minimum = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < minimum)
            {
                minimum = prices[i];
            }

            int currentProfit = prices[i] - minimum;

            if(currentProfit > profit)
            {
                profit = currentProfit;
            }
        }

        return profit;       
    }
};