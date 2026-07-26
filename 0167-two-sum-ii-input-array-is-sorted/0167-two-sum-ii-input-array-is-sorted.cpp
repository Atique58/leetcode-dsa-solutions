class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int first=0;
        int last =numbers.size()-1;

        while(first<last)
        {
            if(numbers[first]+numbers[last]>target)
            {
                last--;
            }
            else if(numbers[first]+numbers[last]<target)
            {
                first++;
            }
            else
            {
                first++;
                last++;
                vector<int> result={first,last};
                return result;  
            }            
        }    
        return{};         
    }
};