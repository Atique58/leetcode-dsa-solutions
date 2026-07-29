class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        set<char> se;
        int left = 0;
        int max_len = 0;
        
        for(int right = 0; right < s.size(); right++)
        {
            while(se.find(s[right]) != se.end())
            {
                se.erase(s[left]);
                left++;
            }
            
            se.insert(s[right]);
            int current_len = right - left + 1;
            if(current_len > max_len)
            {
                max_len = current_len;
            }
        }
        
        return max_len;
    }
};