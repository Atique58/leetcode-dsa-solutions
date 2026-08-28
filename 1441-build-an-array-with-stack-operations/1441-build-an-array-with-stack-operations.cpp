class Solution 
{
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> result;
        int targetIndex = 0;
        
        for (int i = 1; i <= n; i++) 
        {
            // If we already built the whole target array, stop early!
            if (targetIndex == target.size()) 
            {
                break;
            }
            
            // We always push the incoming number
            result.push_back("Push");
            
            // If it matches what we need, move to the next target number
            if (target[targetIndex] == i) 
            {
                targetIndex++;
            }
            // If it doesn't match, we don't actually want it, so throw it away
            else 
            {
                result.push_back("Pop");
            }
        }
        
        return result;
    }
};