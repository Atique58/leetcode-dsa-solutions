class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        // Map to store the "Next Greater Element" for each number in nums2
        unordered_map<int, int> nextGreater;
        stack<int> s;
        
        // 1. Process nums2 to find all the next greater elements
        for (int i = 0; i < nums2.size(); i++) 
        {
            int current = nums2[i];
            
            // While we have numbers waiting in the stack, and the current 
            // number is strictly greater than the one at the top of the stack...
            while (!s.empty() && current > s.top()) 
            {
                // We found the next greater element for the number at the top!
                nextGreater[s.top()] = current;
                s.pop();
            }
            
            // Push the current number onto the stack to wait for ITS next greater element
            s.push(current);
        }
        
        // 2. Any numbers still left in the stack never found a greater element.
        while (!s.empty()) 
        {
            nextGreater[s.top()] = -1;
            s.pop();
        }
        
        // 3. Build the final answer array using the queries from nums1
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) 
        {
            // O(1) lookup to find the pre-calculated answer
            result.push_back(nextGreater[nums1[i]]);
        }
        
        return result;
    }
};