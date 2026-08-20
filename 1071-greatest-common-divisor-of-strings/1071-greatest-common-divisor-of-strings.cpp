class Solution 
{
public:
    string gcdOfStrings(string str1, string str2) 
    {
        // 1. Check if they even share a common repeating pattern
        if (str1 + str2 != str2 + str1) 
        {
            return "";
        }
        
        // 2. Find the mathematical GCD of their lengths
        int gcdLength = gcd(str1.length(), str2.length());
        
        // 3. Return the exact substring from the beginning
        return str1.substr(0, gcdLength);
    }
};