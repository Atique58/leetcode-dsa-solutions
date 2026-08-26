class Solution 
{
public:
    string reverseWords(string s) 
    {
        // This automatically handles all the messy extra spaces
        stringstream ss(s);
        string word;
        vector<string> words;
        
        // Extract each clean word and store it
        while (ss >> word) 
        {
            words.push_back(word);
        }
        
        string result = "";
        
        // Loop through the words backwards to build the final string
        for (int i = words.size() - 1; i >= 0; i--) 
        {
            result += words[i];
            
            // Add a space after every word EXCEPT the very last one
            if (i != 0) 
            {
                result += " ";
            }
        }
        
        return result;
    }
};